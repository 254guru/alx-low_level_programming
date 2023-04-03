#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint - frees the memory of each node of listint_t
 * @head: pointer to the head node of the list
 *
 * Return: freed parameter
 */

void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
