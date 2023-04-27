#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a new node to the end of linked list.
 * @head: pointer to the head of the list
 * @str: string to be duplicated
 *
 * Return:  address of the new element or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	int length = 0;
	list_t *new_node, *temporary_node;

	if (!str)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	while (str[length] != '\0')
		length++;
	new_node->len = length;
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}
	temporary_node = *head;
	while (temporary_node->next)
		temporary_node = temporary_node->next;
	temporary_node->next = new_node;
	return (new_node);
}
