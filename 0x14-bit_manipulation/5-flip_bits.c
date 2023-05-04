#include "main.h"

/**
 * flip_bits - returns number of bits needed to flip
 * to get from one number to another
 * @n: parameter a to flip
 * @m: parameter b
 *
 * Return: fliped parameter value
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int i = n ^ m;
	unsigned int j = 0;

	while (i != 0)
	{
		j += (i & 1);
		i >>= 1;
	}

	return (j);
}
