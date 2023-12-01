#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define welcome "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"
#define enseash "enseash %\n"

void q1() {
    write(STDOUT_FILENO, welcome, 59);
    write(STDOUT_FILENO, enseash, 10);
}