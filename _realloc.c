#include "shell.h"

/**
 * realloc_cpy - Function to Print the existing string in realloc
 * @dest: string to copy to
 * @src: string to copy from (source string)
 * @length: determine the length should be copy to
 *
 * Return: (dest)
 */

char *realloc_cpy(char *dest, char *src, int length)
{
	int i;

	for (i = 0; i < length && src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _realloc - Function to re allocate memory for existing pointer
 * @ptr: pointer
 * @old_size: old size
 * @new_size: new size
 *
 * Return: (pointer)
 * otherwise - null
 */

void *_realloc(void *ptr, int old_size, int new_size)
{
	int length;
	void *newPtr;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size && ptr)
		return (ptr);

	if (!ptr)
	{
		ptr = malloc(new_size);
		if (!ptr)
		{
			perror("malloc");
			return (NULL);
		}
		return (ptr);
	}
	newPtr = malloc(new_size);
	if (!newPtr)
	{
		perror("malloc");
		return (NULL);
	}
	if (new_size > old_size)
		length = old_size;
	else
		length = new_size;

	realloc_cpy(newPtr, (char *)ptr, length);
	free(ptr);

	return (newPtr);
}
