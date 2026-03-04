// GitHub : https://github.com/jesseemendozaa/Assignment-2?tab=readme-ov-file

// A simple shell program that reads a line of input, parses it into arguments,
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// The shell should support the following features:
#define MAXLINE 1024

int main(void)
{
    /* A1: basic shell behavior */
    pid_t pid;
    int status;
    char buf[MAXLINE];

    printf("%% ");
    // The shell should read a line of input, parse it into arguments, and execute the command.
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        // Remove trailing newline
        buf[strcspn(buf, "\n")] = '\0';

        /* A2 special case */
        char *args[128];
        int argc = 0;
        // Parse the input line into arguments
        char *tok = strtok(buf, " \t");
        while (tok != NULL) {
            args[argc++] = tok; // store the argument
            tok = strtok(NULL, " \t");     // get the next token
            }
            args[argc] = NULL;
            // If the user types "quit" or "exit", the shell should exit.
            if (argc > 0 && (strcmp(args[0], "quit") == 0 || strcmp(args[0], "exit") == 0)) {
                break;  // exit shell
            }
            // If the user types "./countnames" followed by zero or more arguments, the shell should execute the countnames program with those arguments.
            if (argc > 0 && strcmp(args[0], "./countnames") == 0) {
            /* if user typed only ./countnames */
            if (argc == 1) {
                pid = fork();
                if (pid < 0) {
                    perror("fork");
                    } 
                else if (pid == 0) {
                    execlp("./countnames", "./countnames", (char *)0);
                    perror("exec");
                    _exit(127);
                } else {
                    waitpid(pid, &status, 0);
                }
            printf("%% ");
            continue;
            }
            // if user typed ./countnames with arguments, fork a child process for each argument and execute countnames with that argument
            for (int i = 1; i < argc; i++) {
                pid = fork();
                if (pid < 0) {
                    perror("fork");
                    continue;
                }
                // In the child process, execute countnames with the argument
                if (pid == 0) {
                    execlp("./countnames", "./countnames", args[i], (char *)0);
                    perror("exec");
                    _exit(127);
                    }
            }
            // In the parent process, wait for all child processes to finish
            for (int i = 1; i < argc; i++) {
                wait(&status);
                }

            printf("%% ");
            continue;
        }

        /* normal behavior */
        pid = fork();
        // In the child process, execute the command
        if (pid == 0) {
            execvp(args[0], args);
            perror("exec");
            _exit(127);
        }
        // In the parent process, wait for the child process to finish
        waitpid(pid, &status, 0);

        printf("%% ");
    }

    return 0;
}
