#include "shell.h"

/**
 * command_counter - function to count number of cmd strings
 * @cmd: command to count
 * @delim: pointer points to delimiters used to split
 *
 * Return: (length) which is integer
 */

int command_counter(const char *cmd, const char *delim)
{
	char *fullCommand, *token;
	int length;

	fullCommand = str_dup(cmd);
	if (!fullCommand)
	{
		perror("str_dup");
		return (-1);
	}
	token = strtok(fullCommand, delim);
	while (token)
	{
		length++;
		token = strtok(NULL, delim);
	}
	free(fullCommand);
	free(token);
	return (length);
}
