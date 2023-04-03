#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * pop_listint - deletes head node and returns head node data
 * @head: pointer to the head node of the list
 *
 * Return: 0
 */

int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	temp = *head;
	data = temp->n;
	*head = (*head)->next;
	free(temp);

	return (data);
}
