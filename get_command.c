#include "shell.h"

/**
 * get_command - Function to get the command
 *						and split it in array of strings
 * @command: which is the pinter of string get by user
 *
 * Return: (commandArray)
 */

char **get_command(const char *command)
{
	char *token, *cmdCpy, **commandArray;
	int i = 0, arrSize;
	const char *delim = " \t\n";

	if (!command)
		return (0);

	arrSize = command_counter(command, delim);
	if (arrSize == 0)
		return (NULL);

	cmdCpy = str_dup(command);
	if (!cmdCpy)
		return (NULL);

	commandArray = malloc(sizeof(char *) * (arrSize + 1));
	if (!commandArray)
	{
		perror("malloc");
		free(cmdCpy);
		return (NULL);
	}
	token = strtok(cmdCpy, delim);
	while (token)
	{
		commandArray[i] = str_dup(token);
		if (!commandArray[i])
		{
			command_free(commandArray);
			free(cmdCpy);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	commandArray[i] = NULL;
	free(cmdCpy);
	return (commandArray);
}
