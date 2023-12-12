#include <stdio.h>
#include "search_algos.h"

/**
 * print_value_checked - simulate printing without using printf
 * @index: position at index
 * @value: param value
 *
 * Return: print message
 */
void print_value_checked(size_t index, int value)
{
	char index_str[20];
	char value_str[20];

	snprintf(index_str, sizeof(index_str), "%zu", index);
	snprintf(value_str, sizeof(value_str), "%d", value);

	char message[50] = "Value checked array[";

	strcat(message, index_str);
	strcat(message, "] = [");
	strcat(message, value_str);
	strcat(message, "]\n");

	fputs(message, stdout);
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
		print_value_checked(i, array[i]);

		if (array[i] == value)
		{
			return (i);
		}
	}

	return (-1);
}
