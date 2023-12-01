#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include "Q1.h"

#define MAX_INPUT_SIZE 100


void q2() {
    char input[MAX_INPUT_SIZE];
    start_prompt();

    while(1) {
        prompt();

        read(STDIN_FILENO, input, sizeof(input));
        input[strcspn(input, "\n")] = '\0';

        pid_t pid = fork();
        if (pid == 0) {
            execlp(input, input, NULL);
        }
        else {
            waitpid(pid, NULL, 0);
        }
    }
}

