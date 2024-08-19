#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdarg.h>

extern char **env;

void print_prompt(void);
int str_len(const char *str);
char *str_cpy(char *dest, char *src);
char *str_dup(const char *str);
char *get_line(void);
char **get_command(const char *command);
int exec_command(char **commandArry, char **environ, char *argv);
int command_counter(const char * cmd, const char *delim);
void command_free(char **commandArr);
void free_variadic(int counter, ...);

#endif
