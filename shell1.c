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
        if (strncmp(buf, "./countnames", 11) == 0) {

            char *args[128];
            int argc = 0;

            char *tok = strtok(buf, " ");
            while (tok != NULL) {
                args[argc++] = tok;
                tok = strtok(NULL, " ");
            }

            for (int i = 1; i < argc; i++) {
                pid = fork();
                if (pid == 0) {
                    execlp("./countnames", "./countnames", args[i], (char *)0);
                    perror("exec");
                    _exit(127);
                }
            }

            while (wait(&status) > 0)
                ;

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