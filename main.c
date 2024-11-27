#include "main.h"

/**
 * main - Entry point for testing the _printf function.
 *
 * Description: This function tests the _printf implementation
 *              with various format specifiers including %c, %s,
 *              and an unsupported specifier %r.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	/* Test printing a single character */
	_printf("%c\n", 'H');

	/* Test printing a null character */
	_printf("%c\n", NULL);

	/* Test printing a string */
	_printf("%s\n", "Strings");

	/* Test printing a null string */
	_printf("%s\n", NULL);

	/* Test printing a null format */
	_printf(NULL, NULL);

	/* Test printing a standard string */
	_printf("Hello\n");

	/* Test an unsupported format specifier */
	_printf("%r\n");

	return (0);
}

