#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/wait.h>

char *getLine(void);
char **string_line_spilt(char *line);
int built_ins(void);
int shell_cd(char **args);
int shell_exit(void);
int launch_shell(char **args);
int execShell(char **args);
int shell_interact();
int main(int argc, char **argv)

#endif
