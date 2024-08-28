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
	long int status = 0;
	int i = 0;

	if (str == NULL || str[0] == '\0')
		return (-1);

	if (str[i] == '-')
	{
		return (-1);
	}

	if (str[i] == '\0')
		return (-1);

	for (; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			status = (status * 10) + (str[i] - '0');
		}
		else
		{
			return (-1);
		}
	}

	return (status);
}
