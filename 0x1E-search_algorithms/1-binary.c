#include <stdio.h>
#include "search_algos.h"
/**
 * binary_search - searches for a value in a sorted array of integers
 * using binary search algorithm
 * @array: pointer to first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: value index otherwise -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t start = 0;
	size_t end = size - 1;
	size_t mid;
	size_t i;

	if (array == NULL)
	{
		return (-1);
	}
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		printf("searching in array: ");
		for (i = start; i <= end; i++)
		{
			printf("%d, ", array[i]);
		}
		printf("\n");

		if (array[mid] == value)
		{
			return (mid);
		}
		else if (array[mid] < value)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
}
