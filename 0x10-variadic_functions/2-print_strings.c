#include "variadic_functions.h"

/**
 * print_strings - prints strings, followed by a new line.
 *
 * @separator: prints strings, followed by a new line.
 * @n: number of parameters
 * Return: Always 0
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	char *str;
	unsigned int i;
	va_list ap;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(ap, char*);
		printf("%s", str ? str : "(nil)");
		if (i < n - 1)
			printf("%s", separator ? separator : "");
	}
	printf("\n");
	va_end(ap);
}
