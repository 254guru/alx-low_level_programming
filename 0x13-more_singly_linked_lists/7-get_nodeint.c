#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns nth node of a listint_t
 * @head: pointer to the head node of the list
 * @index: integer value of the node
 *
 * Return: NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current = head;

	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	return (current == NULL ? NULL : current);
}
