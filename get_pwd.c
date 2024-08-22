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
