#include "hash_tables.h"

/**
 * shash_table_create - creates an empty ordered hash table
 * @size: size of the hash table
 *
 * Return: Pointer to the new hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *s_hash_table = malloc(sizeof(shash_table_t));

	if (!s_hash_table)
		return (NULL);
	s_hash_table->size = size;
	s_hash_table->shead = NULL;
	s_hash_table->stail = NULL;
	s_hash_table->array = malloc(sizeof(shash_node_t) * size);
	if (!s_hash_table->array)
	{
		free(s_hash_table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		s_hash_table->array[i] = NULL;
	}
	return (s_hash_table);
}

/**
 * make_shash_node - makes a node for the sorted hash table
 * @key: key
 * @value: data
 *
 * Return: Pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *s_hash_node;

	s_hash_node = malloc(sizeof(shash_node_t));
	if (!s_hash_node)
		return (NULL);
	s_hash_node->key = strdup(key);
	if (!s_hash_node->key)
	{
		free(s_hash_node);
		return (NULL);
	}
	s_hash_node->value = strdup(value);
	if (!s_hash_node->value)
	{
		free(s_hash_node->key);
		free(s_hash_node);
		return (NULL);
	}
	s_hash_node->next = s_hash_node->snext = s_hash_node->sprev = NULL;
	return (s_hash_node);
}

/**
 * add_to_sorted_list - add a node to the sorted (by key's ASCII) linked list
 * @table: hash table
 * @node: node to add
 *
 * Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *temp;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	temp = table->shead;
	while (temp != NULL)
	{
		if (strcmp(node->key, temp->key) < 0)
		{
			node->snext = temp;
			node->sprev = temp->sprev;
			temp->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		temp = temp->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - sets a key to a value in the hash table
 * @ht: ordered hash table
 * @key: key
 * @value: data
 *
 * Return: 0 on failure, 1 on success
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_v;
	shash_node_t *shn, *temp;

	if (!ht || !ht->array || !ht->size || !key || !strlen(key) || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new_v = strdup(value);
			if (!new_v)
				return (0);
			free(temp->value);
			temp->value = new_v;
			return (1);
		}
		temp = temp->next;
	}
	shn = make_shash_node(key, value);
	if (!shn)
		return (0);
	shn->next = ht->array[index];
	ht->array[index] = shn;
	add_to_sorted_list(ht, shn);
	return (1);
}

/**
 * shash_table_get - retrieve a value from the hash table
 * @ht: ordered hash table
 * @key: key
 *
 * Return: the value associated with key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *temp;

	if (!ht || !ht->array || !ht->size || !key || !strlen(key))
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: ordered hash table
 *
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	char something_printed = 0;

	if (!ht || !ht->array)
		return;
	printf("{");
	temp = ht->shead;
	while (temp)
	{
		if (something_printed)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		something_printed = 1, temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: ordered hash table
 *
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char something_printed = 0;

	if (!ht || !ht->array)
		return;
	printf("{");
	temp = ht->stail;
	while (temp)
	{
		if (something_printed)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		something_printed = 1, temp = temp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht:  ordered hash table
 *
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *next;

	if (!ht || !ht->array || !ht->size)
		return;
	for (i = 0; i < ht->size; i++)
	{
		while (ht->array[i])
		{
			next = ht->array[i]->next;
			free(ht->array[i]->key);
			free(ht->array[i]->value);
			free(ht->array[i]);
			ht->array[i] = next;
		}
	}
	free(ht->array), ht->array = NULL;
	ht->shead = ht->stail = NULL, ht->size = 0;
	free(ht);
}
