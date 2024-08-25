#include "shell.h"

/**
 * pwd_var - Fucntion to get PWD env variable
 * @env: Environment Variables
 *
 * Return: (env[I] + 4)
 * otherwise - (NULL)
 */

char *pwd_var(char **env)
{
	int i = 0, status;

	while (env[i])
	{
		status = str_cmp(env[i], "PWD", 3);
		if (status == 0)
		{
			return (env[i] + 4);
		}
		i++;
	}

	return (NULL);
}

/**
 * cd_pwd - handling cd aruments
 *
 * @env_name: vaiable name
 * @env_val: variable value
 * @env: enviroment variables
 *
 * Return: 0 success, otherwise 1
*/

int cd_pwd(char *env_name, char *env_val, struct env_cpy *env)
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
