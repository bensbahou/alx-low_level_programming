#include <stdio.h>

void constructor_function(void) __attribute__((constructor));

/**
 * constructor_function - prints a message before main function is executed.
 */
void constructor_function(void)
{
	printf("You're beat! and yet, you must allow,\n"
			"I bore my house upon my back!\n");
}
