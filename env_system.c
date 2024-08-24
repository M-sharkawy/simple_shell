#include "shell.h"

/**
 * initialize_env - Function to get the env vars at the beggining
 * @env_arr: envrionment variables
 *
 * Return: (envPtr) which the environemtn variables
 */

env_cpy *initialize_env(char **env_arr)
{
	int i;
	env_cpy *envPtr, *temp, *newNode;

	envPtr = malloc(sizeof(env_cpy));
	if (!envPtr)
	{
		perror("malloc");
		return (NULL);
	}
	envPtr->str = NULL;
	envPtr->next = NULL;
	temp = envPtr;
	for (i = 0; env_arr[i]; i++)
	{
		temp->str = str_dup(env_arr[i]);
		if (!temp->str)
		{
			perror("malloc");
			free(envPtr);
			return (NULL);
		}
		if (env_arr[i + 1])
		{
			newNode = malloc(sizeof(env_cpy));
			if (!newNode)
			{
				perror("malloc");
				free(temp->str);
				free(envPtr);
				return (NULL);
			}
			temp->next = newNode;
			temp = temp->next;
		} else
				temp->next = NULL;
	}
	return (envPtr);
}

/**
 * print_env - Function to print envrionment variables
 * @cmd: command array
 * @env: environment variables
 *
 * Return: (1)
 * otherwise - (0)
 */

int print_env(char **cmd, struct env_cpy *env)
{
	env_cpy *temp = env;

	if (cmd[1])
		return (0);

	while (temp)
	{
		write(STDOUT_FILENO, temp->str, str_len(temp->str));
		write(STDOUT_FILENO, "\n", 1);
		temp = temp->next;
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

int set_env(char **cmd_arr, struct env_cpy *env)
{
	env_cpy *temp = env, *newNode;
	char *envName, *envValue, *newStr;

	if (arr_size(cmd_arr) != 3)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 30);
		return (1);
	}
	envName = cmd_arr[1];
	envValue = cmd_arr[2];
	while (temp->next)
	{
		if (str_cmp(envName, temp->str, str_len(envName)) == 0 &&
		temp->str[str_len(envName)] == '=')
		{
			newStr = full_env_var(envName, envValue);
			if (!newStr)
				return (1);

			free(temp->str);
			temp->str = newStr;
			return (1);
		}
		temp = temp->next;
	}
	newNode = malloc(sizeof(env_cpy));
	if (!newNode)
	{
		perror("malloc");
		return (1);
	}
	newNode->str = full_env_var(envName, envValue);
	if (!newNode->str)
	{
		free(newNode);
		return (1);
	}
	newNode->next = NULL;
	temp->next = newNode;
	return (1);
}
