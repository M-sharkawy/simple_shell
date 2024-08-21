#include "shell.h"

/**
 * exit_shell - function to handle the exit command
 * @cmd_arry: array of commands
 */

void exit_shell(char **cmd_arry)
{
		command_free(cmd_arry);
		exit(0);
}
