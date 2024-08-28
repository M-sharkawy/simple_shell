#include "shell.h"

/**
 * exit_shell - function to handle the exit command
 * @cmd_arry: array of commands
 * @env: environment variables
 * @argv: argument value index 0
 *
 * Return: (1)
 */

int exit_shell(char **cmd_arry, char **env, const char *argv)
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

		if (status == -1)
		{
			write_errors("exit", argv);
			write(STDERR_FILENO, ": Illegal number", 16);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, cmd_arry[1], str_len(cmd_arry[1]));
			write(STDERR_FILENO, "\n", 1);
			command_free(cmd_arry);
			exit(2);
		}

		command_free(cmd_arry);
		exit((int)status);
	}
	return (1);
}
