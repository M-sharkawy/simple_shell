#include "shell.h"

/**
 * initialize_env - Function to get the env vars at the beggining
 * @env_vars: envrionment variables
 *
 * Return: (env_temp) which the environemtn variables
 */

char **initialize_env(char **env_vars)
{
	int i = 0, j;
	char **env_temp;

	while (env_vars[i])
		i++;


	env_temp = malloc(sizeof(char *) * (i + 1));
	if (!env_temp)
	{
		perror("malloc");
		return (NULL);
	}

	for (j = 0; j < i; j++)
	{
		env_temp[j] = malloc(sizeof(char) * (str_len(env_vars[j]) + 1));
		if (!env_temp[j])
		{
			perror("malloc");
			command_free(env_temp);
			return (NULL);
		}
		str_cpy(env_temp[j], env_vars[j]);
	}
	env_temp[i] = NULL;
	return (env_temp);
}

/**
 * print_env - Function to print envrionment variables
 * @cmd: command array
 * @env: environment variables
 *
 * Return: (1)
 * otherwise - (0)
 */

int print_env(char **cmd, char **env)
{
	int i = 0;

	if (cmd[1])
		return (0);

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], str_len(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (1);
}

/**
 * full_env_var - Function to Return the full new variable
 * @cmdOne: command index 1
 * @cmdTwo: command index 2
 *
 * Return: (fullVar)
 */

char *full_env_var(char *cmdOne, char *cmdTwo)
{
	int len1 = str_len(cmdOne);
	int len2 = str_len(cmdTwo);
	char *fullVar = malloc(sizeof(char) * (len1 + len2 + 2));

	if (!fullVar)
	{
		perror("malloc");
		return (NULL);
	}

	str_cpy(fullVar, cmdOne);
	concat(fullVar, "=");
	concat(fullVar, cmdTwo);

	return (fullVar);
}

/**
 * set_env - Function to set a new variable into environment
 * @cmd_arr: array of commands
 * @env: environment variables
 *
 * Return: (1)
 */

int set_env(char **cmd_arr, char **env)
{
	char **newEnv, *variable;
	int i, varLen, envLength = arr_size(env);

	if (arr_size(cmd_arr) != 3)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
		return (1);
	}
	varLen = str_len(cmd_arr[1]);
	for (i = 0; i < envLength; i++)
	{
		if (str_cmp(env[i], cmd_arr[1], varLen) == 0 && env[i][varLen] == '=')
		{
			free(env[i]);
			variable = full_env_var(cmd_arr[1], cmd_arr[2]);
			if (!variable)
				return (1);

			env[i] = variable;
			return (1);
		}
	}
	newEnv = malloc(sizeof(char *) * (envLength + 2));
	if (!newEnv)
		return (1);

	for (i = 0; i < envLength; i++)
		newEnv[i] = env[i];

	variable = full_env_var(cmd_arr[1], cmd_arr[2]);
	if (!variable)
	{
		free(newEnv);
		return (1);
	}
	newEnv[envLength] = variable;
	newEnv[envLength + 1] = NULL;
	free(env);
	env = newEnv;
	return (1);
}
