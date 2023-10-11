#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Performs a linear search to find a specific value
 * in an integer array.
 * 
 * @param array: The array in which to search for the value.
 * @param size: The size of the array.
 * @param value: The value to search for.
 * 
 * @return: Returns the index of the found value,
 * or -1 if the value is not found.
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array || size == 0)
		return (-1);

	while (i < size)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
		i++;
	}

	return (-1);
}
