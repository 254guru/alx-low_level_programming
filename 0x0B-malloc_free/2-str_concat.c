#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * *str_concat - concatenates two strings
 * @s1: parameter one
 * @s2: parameter two
 *
 * Return: result if succesfull, else NULL
 */

char *str_concat(char *s1, char *s2)
{
	size_t s1_len, s2_len;
	char *result;

	s1_len = s1 ? strlen(s1) : 0;
	s2_len = s2 ? strlen(s2) : 0;

	result = malloc(s1_len + s2_len + 1);
	if (result == NULL)
	{
		return (NULL);
	}

	if (s1)
	{
		strcpy(result, s1);
	}

	if (s2)
	{
		strcpy(result + s1_len, s2);
	}

	return (result);
}
