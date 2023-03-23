#include "main.h"

/**
 * print_line - printing lines from -
 * @n: number of times to print -
 *
 * Return: void
 */


void print_line(int n)
{
	int i;

	for (i = 1; i <= n; i++)
		_putchar('_');

	_putchar('\n');
}
