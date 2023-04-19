#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * op_add - add two int
  * @a: first int
  * @b: second int
  *
  * Return: the sum of a & b
  */
int op_add(int a, int b)
{
	return (a + b);
}

/**
  * op_sub - substruct two integers
  * @a: first int
  * @b: second int
  *
  * Return: a - b
  */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
  * op_mul - multiply two int
  * @a: first int
  * @b: second int
  *
  * Return: a * b
  */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
  * op_div - divide two int
  * @a: first int
  * @b: second int
  *
  * Return: a/b
  */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
  * op_mod - calculate the modulo of two int
  * @a: first int
  * @b: second int
  *
  * Return: a % b
  */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
