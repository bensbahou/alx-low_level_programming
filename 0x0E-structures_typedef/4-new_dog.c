#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - create new dog
 * @name: name
 * @age: age
 * @owner: owner
 *
 * Return: pointer to the created dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int nl = 0, ol = 0, i;
	dog_t *dog;

	if (name == NULL || owner == NULL)
		return (NULL);
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	while (name[nl])
		nl++;
	nl++;
	dog->name = malloc(nl * sizeof(char));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	for (i = 0; i < nl; i++)
		dog->name[i] = name[i];
	dog->age = age;
	while (owner[ol])
		ol++;
	ol++;
	dog->owner = malloc(ol * sizeof(char));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	for (i = 0; i < ol; i++)
		dog->owner[i] = owner[i];
	return (dog);
}
