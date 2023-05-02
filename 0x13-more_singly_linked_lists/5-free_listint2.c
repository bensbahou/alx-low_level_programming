#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees a listint_t list.
 * @head: head of list
 * Return: void
 */

void free_listint2(listint_t **head)
{
	if (*head)
	{
		free_listint2((*head)->next);
		free(*head);
	}
}
