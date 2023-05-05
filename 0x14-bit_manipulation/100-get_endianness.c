#include "main.h"
/**
 * get_endianness - checks the endianness.
 *
 * Returns: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned long int integer = 1;
	char *character = (char *)&integer;

	return (*character);
}
