#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXLINE 1024

int main(void)
{
    
    pid_t pid;
    int status;
    char buf[MAXLINE];

    printf("%% ");

    while (fgets(buf, MAXLINE, stdin) != NULL) {

        buf[strcspn(buf, "\n")] = '\0';

        /* A2 special case */
        char *args[128];
        int argc = 0;

        char *tok = strtok(buf, " \t");
        while (tok != NULL) {
            args[argc++] = tok;
            tok = strtok(NULL, " \t");
            }
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

            for (int i = 1; i < argc; i++) {
                pid = fork();
                if (pid < 0) {
                    perror("fork");
                    continue;
                }
                if (pid == 0) {
                    execlp("./countnames", "./countnames", args[i], (char *)0);
                    perror("exec");
                    _exit(127);
                    }
            }

            for (int i = 1; i < argc; i++) {
                wait(&status);
                }

            printf("%% ");
            continue;
        }

        /* normal behavior */
        pid = fork();

        if (pid == 0) {
            execlp(buf, buf, (char *)0);
            perror("exec");
            _exit(127);
        }

        waitpid(pid, &status, 0);

        printf("%% ");
    }

    return 0;
}