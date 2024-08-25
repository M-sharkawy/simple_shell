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
 * struct env_cpy - Structure to hold environment variables
 * @str: env variable with value
 * @next: pointer to the next variable
 */

typedef struct env_cpy
{
	char *str;
	struct env_cpy *next;
} env_cpy;

/**
 * struct built_in - Structure for Built in Commands
 * @cmd: command which is string
 * @f: Pointer to a function which handles the command
 */

typedef struct built_in
{
	char *cmd;
	int (*f)(char **, struct env_cpy **);
} built_in;

void print_prompt(void);
char *get_line(void);
char **get_command(const char *command);
int exec_command(char **cmd_rr, char **envir, char *argv, struct env_cpy *);

int str_len(const char *str);
char *str_cpy(char *dest, char *src);
char *str_dup(const char *str);
int str_cmp(const char *str_one, const char *str_two, int bytes);
char *concat(char *dest, const char *src);

long int _atoi(char *str);

int command_counter(const char *cmd, const char *delim);
void command_free(char **commandArr);
void free_variadic(int counter, ...);

void write_errors(const char *cmd, const char *argv);
void full_error_handling(const char *cmd, const char *argv);
void cd_err_handling(char *mess, int stat);

char *path_variable(struct env_cpy *environment);
int file_check(const char *cmd);
char *path_var_checking(const char *cmd, struct env_cpy *environment);

int handle_build_in(char **cmd_arr, const char *argv, struct env_cpy **env);
int exit_shell(char **cmd, struct env_cpy **env);

int cd_funct(char **commandArr, struct env_cpy *env);
char *get_home(struct env_cpy *env);

int arr_size(char **array);

env_cpy *initialize_env(char **env_arr);
int print_env(char **cmd, struct env_cpy **env);
int set_env(char **cmd_arr, struct env_cpy **env);
int un_set_env(char **cmd_arr, struct env_cpy **env);
char *full_env_var(char *cmdOne, char *cmdTwo);

void delete_node_head(env_cpy **env);

void free_env_list(env_cpy *env);

int cd_pwd(char *env_name, char *env_val, struct env_cpy *env);
char *pwd_var(char **env);

#endif
