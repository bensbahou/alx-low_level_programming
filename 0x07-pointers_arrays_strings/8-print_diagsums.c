#include "main.h"
/**
 * print_diagsums - prints the sums of the two diagonals of a square matrix
 * @a: pointer to start of matrix
 * @size: width of matrix column
 *
 * Return: void
 */

void print_diagsums(int *a, int size)
{
	int i, left_sum = 0, right_sum = 0;

	for (i = 0; i < size; i++)
	{
		left_sum += *(a + (i * size) + i);
		right_sum += *(a + (i * size) + (size - 1 - i));
	}
	printf("%i, %i\n", left_sum, right_sum);
}
