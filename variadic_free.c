#include "shell.h"

/**
 * free_variadic - Function to free all list
 * @counter: number of items
 */

void free_variadic(int counter, ...)
{
	va_list ptr;
	int i;
	char *item;

	va_start(ptr, counter);

	i = 0;
	while (i < counter)
	{
		item = va_arg(ptr, char *);
		free(item);
		i++;
	}
	va_end(ptr);
}
