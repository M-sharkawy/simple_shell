#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>

/**
 * struct built_in - Structure for Built in Commands
 * @cmd: command which is string
 * @f: Pointer to a function which handles the command
 */

typedef struct built_in
{
	char *cmd;
	int (*f)(char **);
} built_in;

void print_prompt(void);
int str_len(const char *str);
char *str_cpy(char *dest, char *src);
char *str_dup(const char *str);
int str_cmp(const char *str_one, const char *str_two, int bytes);
char *get_line(void);
char **get_command(const char *command);
int exec_command(char **commandArry, char **environ, char *argv);
int command_counter(const char *cmd, const char *delim);
void command_free(char **commandArr);
void free_variadic(int counter, ...);
int cd_funct(char **commandArr);
void err_handling(char *mess, int stat);
char *path_variable(char **environment);
char *str_cat(char *dest, const char *src);
char *path_var_checking(const char *cmd, char **environment);
void full_error_handling(const char *cmd, const char *argv);

#endif
