#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: head of list
 * @idx: index of node
 * @n: data for new node
 * Return: address of new node or NULL if failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *temp = *head;
	unsigned int i;

	if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	if (!idx)
	{
		new->n = n;
		new->next = *head;
		*head = new;
		return (new);
	}
	for (i = 0; i < idx - 1; i++)
	{
		if (!temp)
		{
			free(new);
			return (NULL);
		}
		temp = temp->next;
	}
	new->n = n;
	new->next = temp->next;
	temp->next = new;
	return (new);
}
