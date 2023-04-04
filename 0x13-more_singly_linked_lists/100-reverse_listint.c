#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to the head node of the list
 *
 * Return: pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	if (head)
	{
		while (*head)
		{
			next = *head;
			*head = (*head)->next;
			next->next = prev;
			prev = next;
		}

		*head = prev;
		return (*head);
	}

	return (NULL);
}
