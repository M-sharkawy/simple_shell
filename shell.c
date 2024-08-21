#include "shell.h"


/**
 * handle_build_in - Function to handle build in commands
 * @cmd_arr: array of commands
 * @argv: Program name
 *
 * Return: (status)
 */

int handle_build_in(char **cmd_arr, const char *argv)
{
	int status, i;
	built_in arr[] = {
		{"exit", exit_shell},
		{NULL, NULL}
	};

	for (i = 0; arr[i].cmd; i++)
	{
		if (str_cmp(cmd_arr[0], arr[i].cmd, strlen(arr[i].cmd) + 1) == 0)
		{
			status = arr[i].f(cmd_arr);
			if (status == -1)
			{
				full_error_handling(cmd_arr[0], argv);
				command_free(cmd_arr);
				if (isatty(STDIN_FILENO))
					exit(2);
			}
			return (1);
		}
	}
	return (0);
}

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
	int built_in_handled, status;

	(void)argc;

	while (1)
	{
		print_prompt();
		buffer = get_line();
		cmdArr = get_command(buffer);
		free_variadic(1, buffer);

		if (!cmdArr || !cmdArr[0])
		{
			command_free(cmdArr);
			continue;
		}

		built_in_handled = handle_build_in(cmdArr, argv[0]);
		if (!built_in_handled)
			status = exec_command(cmdArr, env, argv[0]);

		if (status != 0)
			continue;

		command_free(cmdArr);
		cmdArr = NULL;
	}

	return (0);
}
