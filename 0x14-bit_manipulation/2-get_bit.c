#include "main.h"
/**
 * get_bit - returns the value of a bit
 * @n: bimary number
 * @index: index starting from 0
 *
 * Return: value of index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}
	return ((n >> index) & 1);
}
