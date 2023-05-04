#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0
 * @n: pointer to parameter to modify
 * @index: bit index
 *
 * Return: 1 otherwise -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	i = ~(1UL << index);
	*n &= i;

	return (1);
}
