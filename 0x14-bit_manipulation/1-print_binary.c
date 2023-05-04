#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: number to print
 * Return: void
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int i = 0;

	mask <<= 63;
	while (!(mask & n) && mask)
		mask >>= 1;
	if (!mask)
	{
		_putchar('0');
		return;
	}
	while (mask)
	{
		if (mask & n)
			_putchar('1');
		else
			_putchar('0');
		mask >>= 1;
		i++;
	}
}
