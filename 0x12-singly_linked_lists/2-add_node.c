#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - add a new node at beginning of a list_t list.
 * @head: head of a list_t list.
 * @str: string to be duplicated.
 * Return: address of the new element or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	unsigned int length = 0;
	list_t *add;

	add = malloc(sizeof(list_t));
	if (!add)
		return (NULL);
	add->str = strdup(str);
	while (str[length] != '\0')
		length++;

	add->len = length;
	add->next = *head;
	*head = add;

	return (add);
}
