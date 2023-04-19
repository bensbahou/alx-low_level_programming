#include "function_pointers.h"

/**
  * int_index - searches for an integer
  * @array: array of intergers
  * @size: size of the array
  * @cmp: funciton used to compare values
  *
  * Return: index of the first with cmp value not null, -1 if not found
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array && cmp)
		{
			while (i < size)
			{
				if (cmp(array[i]) != 0)
					return (i);

				i++;
			}
		}
	}

	return (-1);
}
