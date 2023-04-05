#include "main.h"
/**
 * _strlen - Prints the length of a string.
 * @s: the string to be printed
 * Return: the length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}
/**
 * pal_checker - check if s is palindrome.
 * @s: string base address.
 * @i: left index.
 * @j: rigth index.
 * Return: 1 if s is palindrome, 0 otherwise.
 */
int pal_checker(char *s, int i, int j)
{
	if (s[i] == s[j])
		if (i > j / 2)
			return (1);
		else
			return (pal_checker(s, i + 1, j - 1));
	else
		return (0);
}
/**
 * is_palindrome - check if s is palindrome
 * @s: base address for string.
 *
 * Return: 1 if s is palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	return (pal_checker(s, 0, _strlen(s) - 1));
}