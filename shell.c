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
		free_variadic(1, buffer);

		if (!cmdArr)
			continue;

		if (cmdArr[0])
		{
			if (str_cmp(cmdArr[0], "exit", 5) == 0)
				exit_shell(cmdArr);

			exec_command(cmdArr, env, argv[0]);
		}

		command_free(cmdArr);
	}

	return (0);
}
