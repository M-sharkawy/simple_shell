#include "shell.h"

/**
 * path_variable - Function to get the PATH Variable
 * @environment: environment variables
 *
 * Return: PATH VALUE
 * otherwise - NULL
 */

char *path_variable(char **environment)
{
	int i, status;

	if (!environment)
		return (NULL);

	for (i = 0; environment[i]; i++)
	{
		status = str_cmp(environment[i], "PATH", 4);
		if (status == 0)
			return (environment[i] + 5);
	}

	return (NULL);
}

/**
 * path_var_checking - Function to check Command in PATH Variable
 * @cmd: command to be checked
 * @environment: environment variables
 *
 * Return: (cmdPath) which is command path
 * otherwise - (NULL)
 */

char *path_var_checking(const char *cmd, char **environment)
{
	char *path, *pathCpy, *token, *cmdPath;
	int cmdPathLen;

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			return (str_dup(cmd));
		else
			return (NULL);
	}

	path = path_variable(environment);
	if (!path)
		return (NULL);

	pathCpy = str_dup(path);
	if (!pathCpy)
		return (NULL);

	token = strtok(pathCpy, ":");
	if (!token)
		return (NULL);
	while (token)
	{
		cmdPathLen = str_len(token) + str_len(cmd) + 2;
		cmdPath = malloc(sizeof(char) * cmdPathLen);
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
	free(pathCpy);
	return (NULL);
}
