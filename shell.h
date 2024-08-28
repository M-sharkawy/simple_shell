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
	int (*f)(char **, char **);
} built_in;

void print_prompt(void);
char *get_line(void);
char **get_command(const char *command);
int exec_command(char **cmd_rr, char **envir, char *argv);

int str_len(const char *str);
char *str_cpy(char *dest, char *src);
char *str_dup(const char *str);
int str_cmp(const char *str_one, const char *str_two, int bytes);
char *concat(char *dest, const char *src);

long int _atoi(char *str);

int command_counter(const char *cmd);
void command_free(char **commandArr);
void free_variadic(int counter, ...);

void write_errors(const char *cmd, const char *argv);
void full_error_handling(const char *cmd, const char *argv);
void cd_err_handling(char *mess, int stat);

char *path_variable(char **environment);
int file_check(const char *cmd);
char *path_var_checking(const char *cmd, char **environment);

int handle_build_in(char **cmd_arr, const char *argv, char **env);
int exit_shell(char **cmd, char **env);

int arr_size(char **array);

int print_env(char **cmd, char **env);

#endif
