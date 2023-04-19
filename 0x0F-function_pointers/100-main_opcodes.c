#include <stdlib.h>
#include <stdio.h>

/**
 * print_opcodes - print the opcodes of function given in argument
 * @a: addres of a function
 * @n: bytes to print
 *
 * Return: void
 */
void print_opcodes(char *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%.2hhx", a[i]);
		if (i != n - 1)
			printf(" ");
	}
	printf("\n");

}

/**
 * main - prints the opcodes of itself
 * @argc: number of arguments passed to the function
 * @argv: array of pointers to arguments
 *
 * Return: always O
 */
int main(int argc, char **argv)
{
	int n;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}
	print_opcodes(main, n);
	return (0);
}
