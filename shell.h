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

extern char **env_cpy;

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
char *concat(char *dest, const char *src);
void write_errors(const char *cmd, const char *argv);
void full_error_handling(const char *cmd, const char *argv);
char *path_variable(char **environment);
char *path_var_checking(const char *cmd, char **environment);
int handle_build_in(char **cmd_arr, const char *argv, char **env);
int exit_shell(char **cmd, char **env);
void cd_err_handling(char *mess, int stat);
char *get_home(char **env);
int cd_funct(char **commandArr, char **env);
int arr_size(char **array);
char *realloc_cpy(char *dest, char *src, int length);
void *_realloc(void *ptr, int old_size, int new_size);
char **initialize_env(char **env_vars);
int print_env(char **cmd, char **env);
int set_env(char **cmd_arr, char **env);
char *full_env_var(char *cmdOne, char *cmdTwo);
char *pwd_var(char **env);

#endif
