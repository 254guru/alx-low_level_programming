#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * *_strdup - returns pointer to a new memory
 * @str: the duplicate string
 *
 * Return: NULL IF str is null
 */

char *_strdup(char *str)
{
	size_t len;
	char *new_str;

	if (str == NULL)
	{
		return (NULL);
	}

	len = strlen(str);
	new_str = malloc(len + 1);

	if (new_str == NULL)
	{
		return (NULL);
	}

	strcpy(new_str, str);

	return (new_str);
}
