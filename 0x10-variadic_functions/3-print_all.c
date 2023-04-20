#include "variadic_functions.h"

/**
 * print_all - prints anything
 *
 * @format: list of types of arguments
 *
 * Return: void
 */

void print_all(const char * const format, ...)
{
	int i;
	char *str;
	va_list a_list;

	va_start(a_list, format);
	i = 0;
	while (format && format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(a_list, int));
				if (format[i + 1] != '\0')
					printf(", ");
				break;
			case 'i':
				printf("%i", va_arg(a_list, int));
				if (format[i + 1] != '\0')
					printf(", ");
				break;
			case 'f':
				printf("%f", va_arg(a_list, double));
				if (format[i + 1] != '\0')
					printf(", ");
				break;
			case 's':
				str = va_arg(a_list, char*);
				printf("%s", str ? str : "(nil)");
				if (format[i + 1] != '\0')
					printf(", ");
				break;
			default:
				break;
		}
		i++;
	}
	printf("\n");
	va_end(a_list);
}
