#include "shell.h"

/**
 * command_free - free memory
 * @commandArr: command arry
 *
 */

void command_free(char **commandArr)
{
	int index;

	index = 0;
	while (commandArr[index])
	{
		free(commandArr[index]);
		commandArr[index] = NULL;
		index++;
	}
	free(commandArr);
}
