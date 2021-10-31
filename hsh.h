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



void print_env(char **env);
char *my_getlinr(void);
char *find_path(char **env);
char *get_exec_command(char *token, char *line);
void string_copy(char *dest, char *src, size_t n);
void execute_by_path(char *get, char **av, char **env);
void execute_command(char *get, char **av, char **env);
int main(int ac, char **av, char **env);

#endif
