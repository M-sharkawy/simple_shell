#include "shell.h"

/**
 * cd_err_handling - Function to Handling errors
 * @mess: message to be appeared
 * @stat: stat to determine usage of exit
 */

void cd_err_handling(char *mess, int stat)
{
	perror(mess);
	if (stat != 0)
		exit(EXIT_FAILURE);
}

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
 * get_home - Function to get HOME Variable Value
 * @env: environment variables
 *
 * Return: (env[i] + 5) which is the value of HOME
 * otherwise - (NULL)
 */

char *get_home(char **env)
{
	int i, status;

	if (!env)
		return (NULL);

	for (i = 0; env[i]; i++)
	{
		status = str_cmp(env[i], "HOME", 4);
		if (status == 0)
			return (env[i] + 5);
	}

	return (NULL);
}

/**
 * cd_funct - Function to implement chdir
 * @commandArr: array of the input command line
 * @env: environment variables
 *
 * Return: (cdStat)
 * otherwise - (0)
 */

int cd_funct(char **commandArr, char **env)
{
	int status = str_cmp(commandArr[0], "cd", 2), cdStat, size;
	char *home = get_home(env);

	if (status != 0)
		return (0);

	if (!commandArr[1])
	{
		if (!home)
		{
			write(STDERR_FILENO, "cd: HOME not set\n", 17);
			return (1);
		}
		cdStat = chdir(home);
		if (cdStat != 0)
			cd_err_handling("chdir", cdStat);
	}
	else if (commandArr[1])
	{
		size = arr_size(commandArr);
		if (size > 2)
		{
			write(STDOUT_FILENO, "Too many args for cd command\n", 29);
			return (1);
		}
		else
		{
			cdStat = chdir(commandArr[1]);
			if (cdStat != 0)
				cd_err_handling("chdir", cdStat);
		}
	}

	return (1);
}
