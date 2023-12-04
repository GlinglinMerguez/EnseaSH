# Micro Shell Project - ENSEA

## Overview

This repository contains the ENSEA micro shell project's code. The shell is named "EnseaSH" and it is designed to execute commands and display information about their execution.

- The project is developed by Léo APPOURHCAUX and Yumeng YE
- The code is hosted on Github, with a public repository
- Each question has a separate file

### Question 1 : Displaying welcome message and simple prompt

**Explanation:**
- Define the constants "welcome" and "enseash" to store respectively the welcome message and the prompt
- Use the "write" function from the "unistd.h" library to print messages to the standard out

### Question 2 : REPL implementation and commands execution

**Explanation:**
- The code implements a REPL for our shell program
- Users can input commands at the prompt, and the shell will execute them
- The entered command is executed in a child process using 'fork()' and 'execlp' 
  - The 'fork()' function creates a new process by duplicating the calling process. It returns the process ID (PID) of the child process to the parent and 0 to the child
  - The 'execlp()' function is then used in the child process to execute the entered command
- The parent process waits for the child process to finish using the 'waitpid' function

