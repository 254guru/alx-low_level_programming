#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * listint_len - prints the number of elements in a listint_t list
 * @h: pointer to the head node of the list
 *
 * Return: the number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		len++;
		h = h->next;
	}

	return (len);
}
