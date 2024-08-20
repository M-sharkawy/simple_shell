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
	int i, cmp_status;

	if (!environment)
		return (NULL);

	for (i = 0; environment[i]; i++)
	{
		cmp_status = str_cmp(environment[i], "PATH", 4);
		if (cmp_status == 0)
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
	char *path, *pathCpy, *token, *cmdCpy, *cmdPath;
	const char *delim = ":";
	int cmdPathLen, cmdLength;

	path = path_variable(environment);
	if (!path)
		return (NULL);
	pathCpy = str_dup(path);
	if (!pathCpy)
		return (NULL);
	cmdCpy = str_dup(cmd);
	if (!cmdCpy)
	{
		free_variadic(1, pathCpy);
		return (NULL);
	}
	cmdLength = str_len(cmdCpy);
	token = strtok(pathCpy, delim);
	while (token != NULL)
	{
		cmdPathLen = cmdLength + str_len(token) + 2;
		cmdPath = (char *)malloc(sizeof(char) * cmdPathLen);
		if (!cmdPath)
		{
			free_variadic(2, cmdCpy, pathCpy);
			return (NULL);
		}
		str_cpy(cmdPath, token);
		str_cat(cmdPath, "/");
		str_cat(cmdPath, cmdCpy);
		if (access(cmdPath, X_OK) == 0)
		{
			free_variadic(2, pathCpy, cmdCpy);
			return (cmdPath);
		}
		free(cmdPath);
		token = strtok(NULL, delim);
	}
	free_variadic(2, cmdCpy, pathCpy);
	return (NULL);
}
