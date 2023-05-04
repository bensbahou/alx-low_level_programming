#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another
 * @n: first number
 * @m: second number
 * Return: number of bits to flip to get from n to m
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mask = 1;
	unsigned int count = 0;

	mask <<= 63;
	while (!(mask & n) && !(mask & m) && mask)
		mask >>= 1;
	if (!mask)
		return (0);
	while (mask)
	{
		if ((mask & n) != (mask & m))
			count++;
		mask >>= 1;
	}
	return (count);
}
