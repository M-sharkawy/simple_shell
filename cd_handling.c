#include "shell.h"

/**
 * err_handling - Function to Handling errors
 * @mess: message to be appeared
 * @stat: stat to determine usage of exit
 */

void err_handling(char *mess, int stat)
{
	perror(mess);
	if (stat == 0)
		exit(EXIT_FAILURE);
}

/**
 * cd_funct - Function to implement chdir
 * @commandArr: array of the input command line
 *
 * Return: (status)
 */

int cd_funct(char **commandArr)
{
	char *home = getenv("HOME");
	char *oldPwd = getenv("OLDPWD"), dir[1024];
	int status, strLength = str_len(commandArr[1]);

	if (getcwd(dir, sizeof(dir)) == NULL)
	{
		err_handling("getcwd", 1);
		return (-1);
	}
	if (commandArr[1])
	{
		if (str_cmp(commandArr[1], "-", strLength) == 0)
		{
			if (!oldPwd)
			{
				write(STDERR_FILENO, "cd: OLDPWD not set\n", 20);
				return (-1);
			}
			status = chdir(oldPwd);
			if (status == 0)
				setenv("PWD", oldPwd, 1);
			else
				err_handling("chdir", 1);
		} else
		{
			status = chdir(commandArr[1]);
			if (status == 0)
				setenv("PWD", commandArr[1], 1);
			else
				err_handling("chdir", 1);
			}
	} else
	{
		if (!home)
		{
			write(STDERR_FILENO, "cd: HOME not set\n", 20);
			return (-1);
		}
		status = chdir(home);
		if (status == 0)
			setenv("PWD", home, 1);
		else
			err_handling("chdir", 1);
	}

	return (status);
}
