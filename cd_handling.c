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
 * cd_env - handling cd aruments
 *
 * @env_name: vaiable name
 * @env_val: variable value
 * @env: enviroment variables
 *
 * Return: 0 success, otherwise 1
*/

int cd_env(char *env_name, char *env_val, struct env_cpy *env)
{
	env_cpy *temp = env;
	char *newStr;

	if (str_cmp("PWD", env_name, str_len("PWD")) == 0)
	{
		while (temp)
		{
			if (str_cmp(env_name, temp->str, str_len(env_name)) == 0)
			{
				newStr = full_env_var("PWD", env_val);
				if (!newStr)
					return (1);

				free(temp->str);
				temp->str = newStr;
				return (0);
			}
			temp = temp->next;
		}
	}
	return (1);
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
		if (cd_env("PWD", home, env) != 0)
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
		if (cd_env("PWD", commandArr[1], env) != 0)
			return (1);
	}
	return (1);
}
