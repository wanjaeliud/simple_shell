#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int word_count(char *str);
char **split_string(char *str, char *delim);
char *_getline(void);

#endif
