#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * wildcmp - compares two strings
 * @s1: string to compare
 * @s2: string to be compared, contains a special character
 *
 * Return: 1 if strings are identical
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	if (*s2 == '*')
	{
		int result = wildcmp(s1, s2 + 1);

		if (result == 0)
		{
		result = wildcmp(s1 + 1, s2);
		}

		return (result);

	}

	return (0);
}

