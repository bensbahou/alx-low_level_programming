#include "main.h"
#include <stdlib.h>

/**
 * create_array - creates an array of chars
 * and initializes it with a specific char.
 * @size: the size of the array
 * @c: initial value
 *
 * Return: a pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	int i;

	if (!size)
		return (NULL);

	array = (char *)malloc(sizeof(char) * size);
	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
