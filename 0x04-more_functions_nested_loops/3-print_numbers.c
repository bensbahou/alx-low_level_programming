#include "main.h"

/**
 * print_numbers - print 0 to 9
 * followed by new line
 * Return: void
*/

void print_numbers(void)
{
	char c;

	for (c = '0'; c <= '9'; c++)
	{
	_putchar(c);
	}
	_putchar('\n');
}
