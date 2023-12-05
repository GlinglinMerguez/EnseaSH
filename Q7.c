#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>

#include "Q1.h"

#define MAX_INPUT_SIZE 100
#define MAX_ARGS 20


void q7() {
    char input[MAX_INPUT_SIZE];
    start_prompt();
    prompt();

    while (1) {
        int status;

        read(STDIN_FILENO, input, sizeof(input));
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            write(STDOUT_FILENO, "Bye bye...\n", 9);
            break;
        }

        struct timespec start_time, end_time;
        clock_gettime(CLOCK_REALTIME, &start_time);

        pid_t pid = fork();
        if (pid == 0) {
            char *args[MAX_ARGS];
            int argc = 0;

            char *token = strtok(input, " ");
            while (token != NULL && argc < MAX_ARGS - 1) {
                if (strcmp(token, ">") == 0 || strcmp(token, "<") == 0) {
                    token = strtok(NULL, " ");

                    int fd;
                    if (strcmp(args[argc - 1], ">") == 0) {
                        fd = open(token, O_WRONLY | O_CREAT | O_TRUNC, 0666);
                        if (fd == -1) {
                            perror("open");
                            exit(EXIT_FAILURE);
                        }
                        dup2(fd, STDOUT_FILENO);
                    }
                    else if (strcmp(args[argc - 1], "<") == 0) {
                        fd = open(token, O_RDONLY);
                        if (fd == -1) {
                            perror("open");
                            exit(EXIT_FAILURE);
                        }
                        dup2(fd, STDIN_FILENO);
                    }

                    close(fd);
                    token = strtok(NULL, " ");
                } else {
                    args[argc++] = token;
                    token = strtok(NULL, " ");
                }
            }

            args[argc] = NULL;
            execvp(args[0], args);

            prompt();
        }
        else {
            waitpid(pid, &status, 0);

            char exit_status[50];

            clock_gettime(CLOCK_REALTIME, &end_time);
            if (WIFEXITED(status)) {
                long duration = (end_time.tv_nsec - start_time.tv_nsec)/1000000;
                int length = sprintf(exit_status, "enseash [exit:%d|%ldms] %% ", WEXITSTATUS(status), duration);
                write(STDOUT_FILENO, exit_status, length);
            }
            else if (WIFSIGNALED(status)) {
                long duration = (end_time.tv_nsec - start_time.tv_nsec)/1000000;
                int length = sprintf(exit_status, "enseash [sign:%d|%ldms] %% ", WTERMSIG(status), duration);
                write(STDOUT_FILENO, exit_status, length);
            }
        }
    }
}