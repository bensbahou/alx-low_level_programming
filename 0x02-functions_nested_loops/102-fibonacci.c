#include <stdio.h>

/**
 * main - Prints first 50 Fibonacci numbers, starting with 1 and 2,
 *        separated by a comma followed by a space.
 *
 * Return: Always 0.
 */
int main(void)
{
	int c;
	unsigned long fib1 = 0, fib2 = 1, s;

	for (c = 0; c < 50; c++)
	{
		s = fib1 + fib2;
		printf("%lu", s);

		fib1 = fib2;
		fib2 = s;

		if (c == 49)
			printf("\n");
		else
			printf(", ");
	}

	return (0);
}
