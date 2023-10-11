#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 * Otherwise, a pointer to the first node where the value is located.
 *
 * Description: Prints a value every time it is compared in the list.
 *              Uses the square root of the list size as the jump step.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *n, *j;

	if (list == NULL)
		return (NULL);

	for (n = j = list; j->next != NULL && j->n < value;)
	{
		n = j;
		if (j->express != NULL)
		{
			j = j->express;
			printf("Value checked at index [%ld] = [%d]\n",
				   j->index, j->n);
		}
		else
		{
			while (j->next != NULL)
				j = j->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
		   n->index, j->index);

	for (; n->index < j->index && n->n < value; n = n->next)
		printf("Value checked at index [%ld] = [%d]\n", n->index, n->n);
	printf("Value checked at index [%ld] = [%d]\n", n->index, n->n);

	return (n->n == value ? n : NULL);
}
