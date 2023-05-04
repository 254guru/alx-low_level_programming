#include "main.h"

/**
 * binary_to_uint - converts binary number to unsigned int
 * @b: pointer to string of 0 and 1 chars
 *
 * Return:converted number or 0 if b is NULL OR
 * if there is one or more chars in string b that isn't 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] == '0' || b[i] == '1')
		{
			result = result << 1;
			result += b[i] - '0';
			i++;
		}
		else
		{
			return (0);
		}
	}

	return (result);
}
