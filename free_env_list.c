#include "shell.h"

/**
 * free_env_list - Function to free env linked list
 * @env: environment variables
 */

void free_env_list(env_cpy *env)
{
	env_cpy *temp;

	while (env != NULL)
	{
		temp = env;
		env = env->next;
		free(temp->str);
		free(temp);
	}
}
