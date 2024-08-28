#include "shell.h"

/**
 * arr_size - Function to get array size
 * @array: array to get length
 *
 * Return: (length)
 */

int arr_size(char **array)
{
	int length = 0;

	while (array[length])
		length++;

	return (length);
}

/**
 * print_env - Function to print envrionment variables
 * @cmd: command array
 * @env: environment variables
 * @argv: argument value index 0
 *
 * Return: (1)
 * otherwise - (0)
 */

int print_env(char **cmd, char **env, const char *argv)
{
	int i = 0;

	(void)argv;

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
