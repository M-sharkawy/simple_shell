#include "shell.h"

/**
 * str_len - Function to return string length
 * @str: pointer to a string
 *
 * Return: (i) which is the length
 */

int str_len(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	i += 1;
	return (i);
}

/**
 * str_cpy - Function copy string to another
 * @dest: string which copy will be stored
 * @src: string to copy
 *
 * Return: (dest)
 */

char *str_cpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * str_dup - Function that Copies a string
 * @str: string to be copied
 *
 * Return: (newStr) which is new copied pointer points to string
 */

char *str_dup(const char *str)
{
	int i;
	char *newStr;

	newStr = (char *)malloc(sizeof(char) * str_len(str));
	if (!newStr)
	{
		perror("malloc");
		exit(1);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		newStr[i] = str[i];
	}

	return (newStr);
}
