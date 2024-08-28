#include "shell.h"

/**
 * str_len - Function to return string length
 * @str: pointer to a string
 *
 * Return: (i) which is the length
 */

int str_len(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

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

	if (!str)
		return (NULL);

	newStr = (char *)malloc(sizeof(char) * (str_len(str) + 1));
	if (!newStr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		newStr[i] = str[i];
	}
	newStr[i] = '\0';

	return (newStr);
}

/**
 * str_cmp - Function that compares between two strings
 * @str_one: first string
 * @str_two: second string
 * @bytes: size to be compared
 *
 * Return: (0) Success
 * otherwiese - (1) Faluire
 */

int str_cmp(const char *str_one, const char *str_two, int bytes)
{
	int index;

	for (index = 0; index < bytes; index++)
	{
		if (str_one[index] != str_two[index])
			return (1);
	}

	return (0);
}

/**
 * concat - concatenation between two strings
 * @dest: string to add on
 * @src: string to add from
 *
 * Return: (dest)
 */

char *concat(char *dest, const char *src)
{
	int i = 0, j;

	if (!src || !dest)
		return (dest);

	while (dest[i])
		i++;

	for (j = 0; src[j]; j++)
		dest[j + i] = src[j];

	dest[j + i] = '\0';
	return (dest);
}
