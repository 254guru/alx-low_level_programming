#include "main.h"
#include <stdlib.h>

/**
 * flip_bits - returns number of bits you need to flip
 * @n: first input number
 * @m: second input number
 *
 * Return: 0
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result != 0)
	{
		count += (xor_result & 1);
		xor_result >>= 1;
	}

	return (count);
}
