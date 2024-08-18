#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>


int str_len(char *str);
char *str_cpy(char *dest, char *src);
char *str_dup(const char *str);

#endif
