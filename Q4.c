#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "Q1.h"

#define MAX_INPUT_SIZE 100


void q4() {
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

        pid_t pid = fork();
        if (pid == 0) {
            execlp(input, input, NULL);
            prompt();
        }
        else {
            waitpid(pid, &status, 0);

            char exit_status[30];

            if (WIFEXITED(status)) {
                int length = sprintf(exit_status, "enseash [exit:%d] %% ", WEXITSTATUS(status));
                write(STDOUT_FILENO, exit_status, length);
            }
            else if (WIFSIGNALED(status)) {
                int length = sprintf(exit_status, "enseash [sign:%d] %% ", WTERMSIG(status));
                write(STDOUT_FILENO, exit_status, length);
            }
        }
    }
}