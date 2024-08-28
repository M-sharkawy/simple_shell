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
	}

	status = _atoi(cmd_arry[1]);

    if (status < 0 || status > 255)
    {
        write(STDERR_FILENO, "exit: ", 6);
        write(STDERR_FILENO, cmd_arry[1], str_len(cmd_arry[1]));
        write(STDERR_FILENO, ": numeric argument required\n", 29);
        command_free(cmd_arry);
        exit(2);
    }

    command_free(cmd_arry);
    exit((int)status);

	return (1);
}
