#include "main.h"

/**
 * _strspn - a function that gets the length of a prefix substring
 *
 * @s: the initial segment of
 * @accept: which consist only of bytes from
 *
 * Return: the number of bytes
 */

unsigned int _strspn(char *s, char *accept)
{
	int count = 0, x, y;

	for (x = 0; s[x] != '\0'; x++)
	{
		int found = 0;

		for (y = 0; accept[y] != '\0'; y++)
		{
			if (s[x] == accept[y])
			{
				z++;
				found = 1;
				break;
			}
		}
		if (!found)
			break;
	}
		return (z);

}
