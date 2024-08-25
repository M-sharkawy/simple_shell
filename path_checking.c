#include "shell.h"

/**
 * path_variable - Function to get the PATH Variable
 * @environment: environment variables
 *
 * Return: PATH VALUE
 * otherwise - NULL
 */

char *path_variable(struct env_cpy *environment)
{
	int status;
	env_cpy *temp = environment;

	if (!temp)
		return (NULL);

	while (temp)
	{
		status = str_cmp(temp->str, "PATH", 4);
		if (status == 0)
			return (temp->str + 5);

		temp = temp->next;
	}

	return (NULL);
}

/**
 * file_check - Function to check executable files and direct path
 * @cmd: full command
 *
 * Return: (0) Success
 */

int file_check(const char *cmd)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (0);
		else
			return (-1);
	}
	return (1);
}

/**
 * path_var_checking - Function to check Command in PATH Variable
 * @cmd: command to be checked
 * @environment: environment variables
 *
 * Return: (cmdPath) which is command path
 * otherwise - (NULL)
 */

char *path_var_checking(const char *cmd, struct env_cpy *environment)
{
	char *path, *pathCpy, *token, *cmdPath;
	int cmdPathLen, fileChecks = file_check(cmd);

	if (fileChecks == 0)
		return (str_dup(cmd));
	else if (fileChecks == -1)
		return (NULL);

	path = path_variable(environment);
	if (!path)
		return (NULL);

	pathCpy = str_dup(path);
	if (!pathCpy)
		return (NULL);

	token = strtok(pathCpy, ":");
	while (token)
	{
		cmdPathLen = str_len(token) + str_len(cmd) + 2;
		cmdPath = malloc(sizeof(char) * cmdPathLen);
		if (!cmdPath)
		{
			perror("malloc");
			free(pathCpy);
			return (NULL);
		}
		str_cpy(cmdPath, token);
		concat(cmdPath, "/");
		concat(cmdPath, cmd);
		if (access(cmdPath, X_OK) == 0)
		{
			free(pathCpy);
			return (cmdPath);
		}
		free(cmdPath);
		token = strtok(NULL, ":");
	}
	free_variadic(2, pathCpy, token);
	return (NULL);
}
