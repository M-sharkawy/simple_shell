#include "shell.h"

/**
 * get_line - read user input line
 *
 * Return: 0
*/

char *get_line(void)
{
	char *str;
	size_t num, bytes;

	bytes = getline(&str, &num, stdin);

	if (bytes == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, '\n', 1);
		}
		free(str);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
