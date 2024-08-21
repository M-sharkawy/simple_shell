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

	arrSize = command_counter(command, delim);
	if (arrSize == 0)
		return (NULL);
	cmdCpy = str_dup(command);
	if (!cmdCpy)
	{
		perror("str_dup");
		exit(EXIT_FAILURE);
	}
	commandArray = malloc(sizeof(char *) * (arrSize + 1));
	if (!commandArray)
	{
		perror("malloc");
		free(commandArray);
		free(cmdCpy);
		exit(1);
	}
	token = strtok(cmdCpy, delim);

	while (token)
	{
		commandArray[i] = malloc(sizeof(char) * (str_len(token) + 1));
		if (!commandArray[i])
		{
			perror("malloc");
			command_free(commandArray);
			free_variadic(2, cmdCpy, token);
			exit(1);
		}
		str_cpy(commandArray[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	commandArray[i] = NULL;
	free_variadic(2, cmdCpy, token);
	return (commandArray);
}
