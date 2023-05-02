#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list.
 * @head: head of list
 * Return: sum of all data (n) or 0 if list is empty
 */

int sum_listint(listint_t *head)
{
	return (head ? head->n + sum_listint(head->next) : 0);
}
