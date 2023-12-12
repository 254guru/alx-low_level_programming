#include <stdio.h>
#include "search_algos.h"

/**
 * print_value_checked - simulate printing without using printf
 * @value: param value
 *
 * Return: print message
 */
void print_value_checked(int value)
{
	putchar(value + '0');

}

/**
 * linear_search - searches for a value in an array of integers
 * using linear search algorithm
 * @array: pointer to first element of the array
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: first index otherwise -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		print_value_checked(array[i]);

		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}
