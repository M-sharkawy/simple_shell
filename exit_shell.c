#include "shell.h"

/**
 * exit_shell - function to handle the exit command
 * @cmd_arry: array of commands
 *
 * Return: (cmdStat) which is the status of the command
 */

int exit_shell(char **cmd_arry)
{
	int cmdStat = 0;

	command_free(cmd_arry);
	exit(0);

	return (cmdStat);
}
