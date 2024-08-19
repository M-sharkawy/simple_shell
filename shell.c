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

	(void)argc;

	while (1)
	{
		print_prompt();
		buffer = get_line();
		cmdArr = get_command(buffer);

		if (!cmdArr)
			continue;

		if (cmdArr[0])
			exec_command(cmdArr, env, argv[0]);
	}

	return (0);
}
