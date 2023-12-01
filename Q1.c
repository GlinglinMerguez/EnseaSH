#include <stdio.h>
#include <unistd.h>

#define welcome "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define enseash "enseash % "

void start_prompt() {
    write(STDOUT_FILENO, welcome, 59);
}

void prompt() {
    write(STDOUT_FILENO, enseash, 10);
}
