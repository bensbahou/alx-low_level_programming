#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: pointer to the memory previously allocated with malloc
 * @old_size: the size of the allocated space for ptr
 * @new_size: the new size of the new memory block
 *
 * Return: pointer allocate new size memory, or NULL if it fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	int i, n = new_size;
	char *copy = ptr;

	if (!ptr)
	{
		p = malloc(new_size);
		return (p);
	}
	else if (new_size)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (!p)
		return (NULL);
	if (new_size > old_size)
		n = old_size;
	for (i = 0; i < n; i++)
		p[i] = copy[i];
	free(ptr);
	return (p);
}
