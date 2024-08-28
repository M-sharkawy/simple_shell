#include "shell.h"

/**
 * write_errors - Function to print standard error
 * @cmd: string which is the command
 * @argv: executable file name
 */

void write_errors(const char *cmd, const char *argv)
{
	static int errors = 1;
	int length = 0, errorsCpy = errors;
	char *mess;

	while (errorsCpy > 0)
	{
		length++;
		errorsCpy /= 10;
	}

	if (length == 0)
		length = 1;

	mess = malloc(sizeof(char) * (length + 1));
	if (!mess)
	{
		perror("malloc");
		return;
	}

	mess[length] = '\0';
	errorsCpy = errors;

	write(STDERR_FILENO, argv, strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	while (length > 0)
	{
		mess[length - 1] = '0' + (errorsCpy % 10);
		errorsCpy /= 10;
		length--;
	}
	write(STDERR_FILENO, mess, strlen(mess));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));

	free(mess);
	errors++;
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
		write(STDERR_FILENO, ": not found\n", 13);
	}
	else if (access(cmd, X_OK) != 0)
	{
		write_errors(cmd, argv);
		write(STDERR_FILENO, ": Permission denied\n", 21);
	}
}

/**
 * exec_command - excutable file for commands
 * @cmd_rr: command arry
 * @envir: environment
 * @argv: first arg value
 *
 * Return: 0 success
 */

int exec_command(char **cmd_rr, char **envir, char *argv)
{
	pid_t id;
	int status;
	char *path = path_var_checking(cmd_rr[0], envir);

	if (!path)
	{
		full_error_handling(cmd_rr[0], argv);
		free(path);
		if (isatty(STDIN_FILENO))
			return (127);
		exit(127);
	}

	id = fork();
	if (id < 0)
	{
		perror("fork");
		command_free(cmd_rr);
		free(path);
		exit(EXIT_FAILURE);
	} else if (id == 0)
	{
		status = execve(path, cmd_rr, envir);
		if (status == -1)
		{
			perror(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(path);
		waitpid(id, &status, 0);
	}
	return (0);
}
