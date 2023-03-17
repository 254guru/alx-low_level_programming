#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to previous memory allocation
 * @old_size: size in bytes of allocated space for ptr
 * @new_size: size of the new memory block
 *
 * Return: NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}

	if (old_size == new_size)
	{
		return (ptr);
	}

	new_ptr = malloc(new_size);

	memcpy(new_ptr, ptr, (old_size < new_size) ? old_size : new_size);

	free(ptr);

	return (new_ptr);
}
