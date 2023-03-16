#include "main.h"
#include <stdlib.h>
/**
 * *string_nconcat - concatenates two strings
 * @s1: string one
 * @s2: string two
 * @n: newly allocated memory
 *
 * Return: NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int s1_len = 0, s2_len = 0, i, j;

	if (s1 == NULL)
	{
		s1 = "";
	}
	while (s1[s1_len] != '\0')
	{
		s1_len++;
	}
	while (s2[s2_len] != '\0')
	{
		s2_len++;
	}
	if (n >= s2_len)
	{
		n = s2_len;
	}

	concat = malloc(sizeof(char) * (s1_len + n + 1));
	if (concat == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < s1_len; i++)
	{
		concat[i] = s1[i];
	}
	for (j = 0; j < n; j++)
	{
		concat[i + j] = s2[j];
	}
	concat[i + j] = '\0';

	return (concat);
}
