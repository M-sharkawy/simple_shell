#include "shell.h"

/**
 * _atoi - convert string to interger
 *
 * @str: pointer to the string
 *
 * Return: integer
*/

long int _atoi(char *str)
{
	int status = 0, i;

	if (str == NULL)
		return (-1);
	if (!str[1])
	{
		status = str[0] - '0';
		return (status);
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			status = (status * 10) + (str[i] - '0');
		else
			return (-1);
	}

	return (status);
}
