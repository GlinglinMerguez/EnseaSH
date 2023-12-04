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

### Question3 : Shell termination with "exit" command ###

**Explanation:**
- If the user enters the command "exit", the shell print a "Goodbye" message and exits the loop
- The loop continues to read commands until the "exit" command is encountered

### Question 4 : Displaying exit code of the previous command in the prompt ###

**Explanation:**
- After executing each command, the shell captures the exit status using the 'wait' system call
- If the previous command exited normally, the shell displays [exit:<exit_code>] in the prompt
- If the previous command was terminated by a signal, the shell displays [sign:<signal_number>] in the prompt

### Question 5 : Measuring execution time of commands using 'clock_gettime' ###

**Explanation:**
- Before executing each command, the shell records the start time
- After the command finishes, the shell records the end time and calculate the elapsed time
- The shell then displays the exit code or signal along with the execution time in milliseconds in the prompt

### Question 6 : ###

**Explanation:**
- Be