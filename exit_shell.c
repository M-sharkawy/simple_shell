#include "shell.h"

/**
 * exit_shell - function to handle the exit command
 * @cmd_arry: array of commands
 * @env: environment variables
 *
 * Return: (1)
 */

int exit_shell(char **cmd_arry, char **env)
{
	long int status;

	(void)env;
	if (!cmd_arry[1])
	{
		command_free(cmd_arry);
		exit(0);
	} else
	{
		status = _atoi(cmd_arry[1]);
		if (status < 0)
			return (-1);

		command_free(cmd_arry);
		exit(status);
	}

	return (1);
}
