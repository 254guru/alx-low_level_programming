#include "main.h"

/**
 * string_toupper - changes all lowwercase letters to uppercase
 * @p: string to be modified
 *
 * Return: char var
 */

char *string_toupper(char *p)
{
	int a = 0;

	while (p[a])
	{
		if (p[a] >= 97 && p[a] <= 122)
		{
			p[a] -= 32;
		}

		a++;
	}

	return (p);
}
