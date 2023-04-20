#include "variadic_functions.h"

/**
 * sum_them_all - returns the sum of all its parameters
 * 
 * @n: the number of parameters
 * @... : integers to sum
 *
 * Return: Sum of all its parameters or 0 in n == 0
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int i;
	va_list ap;

	va_start(ap, n);

	for (i = 0; i < n; i++)
		sum += va_arg(ap, int);

	va_end(ap);

	return (sum);
}
