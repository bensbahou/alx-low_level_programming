#include "lists.h"

/**
 * dlistint_len - count the number of nodes in the linked list
 * @h: the beginning of a linked list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

