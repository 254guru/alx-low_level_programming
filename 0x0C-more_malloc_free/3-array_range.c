#include "main.h"
#include <stdlib.h>

/**
 * *array_range - creates an array of integers
 * @min: the lowest integer
 * @max: the highest integer
 *
 * Return: NULL
 */

int *array_range(int min, int max)
{
	int *ar, i, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	ar = malloc(size * sizeof(int));

	if (ar == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		ar[i] = min + i;

	return (ar);
}
