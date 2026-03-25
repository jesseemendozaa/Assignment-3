// GitHub : https://github.com/jesseemendozaa/Assignment-3

// A simple shell program that reads a line of input, parses it into arguments,
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// The shell should support the following features:
#define MAXLINE 1024
#define MAX_NAMES 1000 // 1000 distinct names
#define MAX_NAME_LENGTH 31

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int count;
} NameCountData;

typedef enum
{
    TYPE_NAMECOUNT = 1,
    TYPE_B
} MessageType;

typedef struct
{
    MessageType type;
    size_t size;
} MessageHeader;

typedef struct
{
    MessageHeader header;
    NameCountData data;
} NameCountMessage;

// Merge one child result into the parent's combined name/count tables.
static void merge_name_count(char names[MAX_NAMES][MAX_NAME_LENGTH], int counts[MAX_NAMES], int *lengthCount, const NameCountData *data)
{
    int found = 0;

    for (int i = 0; i < *lengthCount; i++)
    {
        if (strcmp(names[i], data->name) == 0)
        {
            counts[i] += data->count;
            found = 1;
            break;
        }
    }

    if (!found && *lengthCount < MAX_NAMES)
    {
        strncpy(names[*lengthCount], data->name, MAX_NAME_LENGTH - 1);
        names[*lengthCount][MAX_NAME_LENGTH - 1] = '\0';
        counts[*lengthCount] = data->count;
        (*lengthCount)++;
    }
}

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

            if (argc == 0)
            {
                printf("%% ");
                continue;
            }

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

            int fd[2];
            if (pipe(fd) == -1) 
            {
                perror("pipe");
                printf("%% ");
                continue;
            }

            char finalNames[MAX_NAMES][MAX_NAME_LENGTH];
            int finalCounts[MAX_NAMES];
            int finalLengthCount = 0;
            pid_t children[128];
            int num_children = 0;

            // Initialize the parent's aggregate table before reading from the pipe.
            for (int i = 0; i < MAX_NAMES; i++)
            {
                finalNames[i][0] = '\0';
                finalCounts[i] = 0;
            }

            // if user typed ./countnames with arguments, fork a child process for each argument and execute countnames with that argument
            for (int i = 1; i < argc; i++) {
                pid = fork();
                if (pid < 0) {
                    perror("fork");
                    continue;
                }
                // In the child process, execute countnames with the argument
                if (pid == 0) 
                {
                    close(fd[0]);

                    // Reserve fd 3 as the data channel back to the shell parent.
                    if (fd[1] != 3) 
                    {
                        if (dup2(fd[1], 3) == -1) 
                        {
                            perror("dup2");
                            _exit(127);
                        }
                    }
                    close(fd[1]);
                    
                    execlp("./countnames", "./countnames", args[i], (char *)0);
                    perror("exec");
                    _exit(127);
                    }
                    else
                    {
                        children[num_children++] = pid;
                    }
            }

            close(fd[1]);

            NameCountMessage message;
            ssize_t BR;

            // Read one full message at a time so each header stays paired with its payload.
            while((BR = read(fd[0], &message, sizeof(NameCountMessage))) > 0) 
            {
                if(BR == (ssize_t)sizeof(NameCountMessage) &&
                   message.header.type == TYPE_NAMECOUNT &&
                   message.header.size == sizeof(NameCountData))
                {
                    merge_name_count(finalNames, finalCounts, &finalLengthCount, &message.data);
                }
            }

            close(fd[0]);

            for (int i = 0; i < num_children; i++) 
            {
                waitpid(children[i], &status, 0);
            }

            // Print the merged counts after every child has finished writing.
            for (int i = 0; i < finalLengthCount; i++)
            {
                printf("%s: %d\n", finalNames[i], finalCounts[i]);
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
