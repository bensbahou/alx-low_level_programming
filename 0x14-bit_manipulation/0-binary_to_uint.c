#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Return: converted number or 0 if b is NULL
 * or there is a char that is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	while (b[i])
	{
		if (b[i] == '0' || b[i] == '1')
		{
			num <<= 1;
			num += b[i] == '1' ? 1 : 0;
			i++;
		}
		else
			return (0);
	}
	return (num);
}
