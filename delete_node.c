#include "shell.h"

/**
 * delete_node_head - Function to delete head node
 * @env: pointer to envorionment variables pointer
 */

void delete_node_head(env_cpy **env)
{
	struct env_cpy *temp = *env;

	if (temp)
	{
		*env = temp->next;
		free(temp->str);
		free(temp);
	}
}
