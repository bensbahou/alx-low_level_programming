#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: head of list
 * Return: pointer to first node of reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *temp = *head, *next;

	if (!head || !*head)
		return (NULL);
	if (!(*head)->next)
		return (*head);
	next = temp->next;
	temp->next = NULL;
	while (next)
	{
		temp = next;
		next = next->next;
		temp->next = *head;
		*head = temp;
	}
	return (*head);
}

