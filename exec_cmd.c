#include "shell.h"

/**
 * write_errors - Function to print standard error
 * @cmd: string which is the command
 * @argv: executable file name
 */

void write_errors(const char *cmd, const char *argv)
{
	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
}

/**
 * full_error_handling - Function to print arror
 * @cmd: string which is the command
 * @argv: executable file name
 */

void full_error_handling(const char *cmd, const char *argv)
{
	if (access(cmd, F_OK) != 0)
	{
		write_errors(cmd, argv);
		write(STDERR_FILENO, ": No such file or directory\n", 28);
	}
	else if (access(cmd, X_OK) != 0)
	{
		write_errors(cmd, argv);
		write(STDERR_FILENO, ": Permission denied\n", 20);
	}
}

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
	char *commandPath = path_var_checking(commandArry[0], environ);

	if (!commandPath)
	{
		full_error_handling(commandPath, argv);
		if (isatty(STDIN_FILENO))
			return (127);
		exit(127);
	}


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
