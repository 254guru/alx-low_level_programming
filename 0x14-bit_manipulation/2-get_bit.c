#include "main.h"

/**
 * get_bit - returns the value of a bit at given index
 * @n: parameter to get bit
 * @index: index starting from 0
 *
 * Return: value of bit at index or -1 if failed
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

	return ((n >> index) & 1);
}
