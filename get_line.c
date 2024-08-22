#include "shell.h"

/**
 * get_line - read user input line
 *
 * Return: 0
*/

char *get_line(void)
{
	char *str = NULL;
	size_t num = 0;
	ssize_t bytes;

	bytes = getline(&str, &num, stdin);

	if (bytes == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		free(str);
		exit(EXIT_SUCCESS);
	}

	if (bytes <= 0)
	{
		free(str);
		return (NULL);
	}
	if (str[0] == '\n')
	{
		free(str);
		return (NULL);
	}

	return (str);
}
