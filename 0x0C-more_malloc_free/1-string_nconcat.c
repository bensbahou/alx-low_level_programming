#include "main.h"

/**
 * string_nconcat - concatenates two strings.
 *
 * @s1: first string
 * @s2: second string
 * @n:  max number of strings to concatinate
 *
 * Return: pointer to the concatenated string if no errors
 * elsewhere return NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int x = 0, y = 0, z;
	char *s;

	if (s1)
	{
		while (s1[x] != '\0')
			x++;
	}
	if (s2)
	{
		while (s2[y] != '\0' && y < n)
			y++;
	}

	s = malloc(sizeof(char) * (x + y + 1));
	if (!s)
		return (NULL);
	for (z = 0; z < x; z++)
		s[z] = s1[z];
	for (z = 0; z < y; z++)
		s[z + x] = s2[z];
	s[x + y] = '\0';
	return (s);
}

