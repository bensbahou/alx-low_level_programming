#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: pointer to generated string in success else NULL
 */
char *argstostr(int ac, char **av)
{
	char *string, *s;
	int i, j, k, length = 0;

	if (!(ac && av))
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		s = av[i];
		j = 0;

		while (s[j++])
			length++;
		length++;
	}

	string = (char *)malloc(sizeof(char) * (length + 1));
	if (!string)
		return (NULL);

	for (i = 0, j = 0; i < ac && j < length; i++)
	{
		s = av[i];
		k = 0;

		while (s[k])
		{
			string[j] = s[k];
			k++;
			j++;
		}
		string[j] = '\n';
		j++;
	}
	string[j] = '\0';

	return (string);
}
