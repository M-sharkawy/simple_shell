#include "shell.h"

/**
 * exit_shell - function to handle the exit command
 * @cmd_arry: array of commands
 * @env: environment variables
 *
 * Return: (cmdStat) which is the status of the command
 */

int exit_shell(char **cmd_arry, char ***env)
{
	int cmdStat = 1;

	(void)env;
	command_free(cmd_arry);
	exit(0);

	return (cmdStat);
}
