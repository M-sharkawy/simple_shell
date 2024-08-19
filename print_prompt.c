#include "shell.h"

/**
 * print_prompt - Function to print $
 */

void print_prompt(void)
{
	char *str = "$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, str, 2);
	}
}
