#include "main.h"

/**
* _isdigit - check for a digit (0 through 9).
* @c: char to check
* Return:  1 if character is digit 0 if not
**/

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
