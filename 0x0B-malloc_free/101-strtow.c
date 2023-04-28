#include "main.h"
#include <stdlib.h>

/**
 * strtow - splits a string into words.
 * @str: the string to split
 *
 * Return: returns a pointer to an array of strings
 */

char **strtow(char *str)
{
	char **words = (char **)malloc(sizeof(char *) * (2));
	if(!str)
		return NULL;

	return (words);
}
