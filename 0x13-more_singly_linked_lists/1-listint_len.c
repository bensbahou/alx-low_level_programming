#include "lists.h"

/**
 * listint_len - count the number of nodes in a linked listint_t list.
 *
 * @h: head of list
 *
 * Return: number of nodes
 *
 */

size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	if (h)
		count += 1 + listint_len(h->next);

	return (count);
}
