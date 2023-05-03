#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t.
 * @head: head of list
 * @index: index of node
 * Return: 1 if succeeded, -1 if failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head, *temp_second;
	unsigned int i;

	if (!head || !*head)
		return (-1);
	if (!index)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}
	for (i = 0; i < index - 1; i++)
	{
		if (!temp)
			return (-1);
		temp = temp->next;
	}
	temp_second = temp->next;
	temp->next = temp_second->next;
	free(temp_second);
	return (1);
}
