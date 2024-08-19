#include "shell.h"

/**
 * main - Entry Point
 * @argc: argument counter
 * @argv: argument value
 * @env: environment vairiable
 *
 * Return: (0)
 */

int main(int argc, char *argv[], char **env)
{
	char *buffer = NULL, **cmdArr;
	size_t n = 0;
	ssize_t bytes;

	(void)argc;
	(void)argv;

	while (1)
	{
		print_prompt();
		bytes = getline(&buffer, &n, stdin);
		if (bytes > 1)
			cmdArr = get_command(buffer);
		if (!cmdArr)
			continue;

		if (cmdArr[0])
			exec_command(cmdArr, env);
	}

	return (0);
}
