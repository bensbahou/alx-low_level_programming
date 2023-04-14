#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: min value
 * @max: max value
 *
 * Return: pointer to the created array or NULL if it fails.
 */
int *array_range(int min, int max)
{
	int *ptr, i, size = max - min + 1;

	if (size <= 0)
		return (NULL);

	ptr = malloc(sizeof(int) * size);

	if (!ptr)
		return (NULL);

	for (i = 0; i < size; i++)
		ptr[i] = min + i;

	return (ptr);
}
