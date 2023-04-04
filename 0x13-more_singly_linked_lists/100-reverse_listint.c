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
	listint_t *rest;

	if (*head == NULL || (*head)->next == NULL)
		return (*head);

	rest = reverse_listint(&(*head)->next);
	(*head)->next = *head;
	(*head)->next = NULL;

	return (rest);
}
