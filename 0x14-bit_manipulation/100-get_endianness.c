<F2>#include "main.h"
/**
 * get_endianness - checks the endianness.
 *
 * Returns: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	int integer;
	char *character;

	integer = 1;
	character = (char *)&integer;

	return (*character);
}
