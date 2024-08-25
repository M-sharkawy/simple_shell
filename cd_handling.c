#include "shell.h"

/**
 * cd_err_handling - Function to Handling errors
 * @mess: message to be appeared
 * @stat: stat to determine usage of exit
 */

void cd_err_handling(char *mess, int stat)
{

	(void)stat;
	perror(mess);
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

char *get_home(struct env_cpy *env)
{
	int status;
	env_cpy *temp = env;

	if (!env)
		return (NULL);

	while (temp)
	{
		status = str_cmp(temp->str, "HOME", 4);
		if (status == 0)
			return (temp->str + 5);

		temp = temp->next;
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

int cd_funct(char **commandArr, struct env_cpy *env)
{
	int status = str_cmp(commandArr[0], "cd", 2);
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
		if (chdir(home) != 0)
		{
			cd_err_handling("chdir", 1);
			return (1);
		}
		if (cd_pwd("PWD", home, env) != 0)
			return (1);
	}
	else if (commandArr[1])
	{
		if (arr_size(commandArr) > 2)
		{
			write(STDOUT_FILENO, "Too many args for cd command\n", 29);
			return (1);
		}
		if (chdir(commandArr[1]) != 0)
		{
			cd_err_handling("chdir", 1);
			return (1);
		}
		if (cd_pwd("PWD", commandArr[1], env) != 0)
			return (1);
	}
	return (1);
}
