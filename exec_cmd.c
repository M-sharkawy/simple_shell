#include "shell.h"

/**
 * exec_command - excutable file for commands
 * @commandArry: command arry
 * @environ: environment
 * @argv: first arg value
 *
 * Return: 0 success
 */

int exec_command(char **commandArry, char **environ, char *argv)
{
	pid_t id;
	int status;

	id = fork();
	if (id < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (id == 0)
	{
		status = execve(commandArry[0], commandArry, environ);
		if (status == -1)
		{
			perror(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(id, &status, 0);
	}
	return (0);
}
