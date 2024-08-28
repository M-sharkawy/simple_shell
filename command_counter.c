#include "shell.h"

/**
 * command_counter - function to count number of cmd strings
 * @cmd: command to count
 *
 * Return: (length) which is integer
 */

int command_counter(const char *cmd)
{
	char *fullCommand, *token;
	int length = 0;
	const char *delim = " \t\n";

	fullCommand = str_dup(cmd);

	token = strtok(fullCommand, delim);
	while (token)
	{
		length++;
		token = strtok(NULL, delim);
	}
	free_variadic(2, fullCommand, token);
	return (length);
}
