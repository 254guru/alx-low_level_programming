#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * *malloc_checked - returns a pointer to the allocated memory
 * @b: specifies the number of bytes to allocate
 *
 * Return: pointer
 */

void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
	{
		exit(98);
	}

	return (p);
}
