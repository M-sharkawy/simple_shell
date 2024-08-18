#include "shell.h"

/**
 * main - Entry Point
 *
 * Return: (0)
 */

int main(void)
{
	int bytes;
	char *buffer;
	ssize_t n = 0;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		n = getline(&buffer, &n, stdin);
		printf("%s", buffer);
	}

	return (0);
}


// martin local 4 files
// master
// mostafa local 3 files