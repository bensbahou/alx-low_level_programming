#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 *
 * @b: number of bytes to be allocated
 *
 * Return: a pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *i = malloc(b);

	if (!i)
		exit(98);
	return (i);

}
