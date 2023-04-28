#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: head of list
 * Return: number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	if (h)
	{
		printf("%d\n", h->n);
		count += 1 + print_listint(h->next);
	}

	return (count);
}
