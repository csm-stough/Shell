#ifndef SHELL_H
#define SHELL_H

#define RPE_RL_BUFSIZE 1024
#define RPE_TOK_BUFSIZE 64
#define RPE_TOK_DELIM " \t\r\n\a"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * This basic shell operates on a Read/Parse/Execute loop:
 * -Read: read the command from STDIN
 * -Parse: seperates the command into a program and arguments
 * -Execute: run the command
 */
void rpe_loop();

/*
 * Reads a line of input from the user. Accounts for the user entering a command longer
 * than the buffer size.
 */
char* rpe_read_line();

/*
 * This function "tokenizes" the string 'line' and returns an array of these tokens
 */
char** rpe_split_line(char* line);

/*
 * This function uses the system call 'fork', and 'exec' to start a new process from our 
 * given command
 */
int rpe_launch(char** args);

#endif
