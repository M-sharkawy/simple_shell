#include "shell.h"


/**
 * handle_build_in - Function to handle build in commands
 * @cmd_arr: array of commands
 * @argv: Program name
 *
 * Return: (status)
 */

int handle_build_in(char **cmd_arr, const char *argv, char **env)
{
	int status, i;
	built_in arr[] = {
		{"exit", exit_shell}, {"env", print_env},
		{"setenv", set_env},
		{NULL, NULL}
	};

	for (i = 0; arr[i].cmd; i++)
	{
		if (str_cmp(cmd_arr[0], arr[i].cmd, strlen(arr[i].cmd) + 1) == 0)
		{
			status = arr[i].f(cmd_arr, env);
			printf("status--> %d\n", status);
			if (status == -1)
			{
				full_error_handling(cmd_arr[0], argv);
				command_free(cmd_arr);
				if (isatty(STDIN_FILENO))
					exit(2);
			}
			return (status);
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
	char *buffer = NULL, **cmdArr, **env_cpy = initialize_env(env);
	int builtInStat, cdStat;

	(void)argc;

	while (1)
	{
		cdStat = 1;
		print_prompt();
		buffer = get_line();
		if (!buffer || !buffer[0])
		{
			free(buffer);
			continue;
		}
		cmdArr = get_command(buffer);
		free(buffer);
		if (!cmdArr || !cmdArr[0])
		{
			command_free(cmdArr);
			continue;
		}

		builtInStat = handle_build_in(cmdArr, argv[0], env_cpy);
		if (builtInStat == 0)
			cdStat = cd_funct(cmdArr, env_cpy);

		if (cdStat == 0)
			exec_command(cmdArr, env, argv[0]);

		printf("%d -- %d\n", builtInStat, cdStat);
		command_free(cmdArr);
		cmdArr = NULL;
	}

	return (0);
}
