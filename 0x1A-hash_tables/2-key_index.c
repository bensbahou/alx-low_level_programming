#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 * @key: key
 * @size: size of the array of the hash table
 *
 * Return: index for the key in the hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
