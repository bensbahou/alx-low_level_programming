#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list.
 *
 * @head: head of the list
 */
void free_list(list_t *head)
{
	if (head)
	{
		if (head->str)
			free(head->str);
		free_list(head->next);
		free(head);
	}
}
