#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp;
	char something_printed = 0;

	if (!ht || !ht->array)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp != NULL)
		{
			if (something_printed)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			something_printed = 1;
			temp = temp->next;
		}
	}
	printf("}\n");
}
