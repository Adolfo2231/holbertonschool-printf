#include "main.h"

/**
 * handle_specifier - Processes a single format specifier.
 * @format: The format specifier to handle.
 * @args: The list of arguments for the specifier.
 *
 * Return: The number of characters printed for the specifier.
 */

int handle_specifier(const char *format, va_list args)
{
	int count = 0;

	if (!format)
		return (-1);

	switch (*format)
	{
		case 'c':
			count += handlers_c(args);
			break;
		case 's':
			count += handlers_s(args);
			break;
		case 'i':
		case 'd':
			count += handlers_di(args);
			break;
		case '%':
			count += _putchar('%');
			break;
		case 'r':
			count += _putchar('%');
			count += _putchar('r');
			break;
		default:
			count += _putchar(*format);
			break;
	}
	return (count);
}


/**
 * handlers_c - Handles the %c format specifier for characters.
 * @args: The list of variable arguments passed to _printf.
 *
 * Return: The number of characters printed.
 */

int handlers_c(va_list args)
{
	int count = 0;

	count += _putchar(va_arg(args, int));

	return (count);


}

/**
 * handlers_s - Handles the %s format specifier for strings.
 * @args: The list of variable arguments passed to _printf.
 *
 * Return: The number of characters printed.
 */
int handlers_s(va_list args)
{
	char *p = va_arg(args, char *);
	int count = 0;

	if (!p)
		p = "(null)";

	while (*p)
	{
		count += _putchar(*p);
		p++;
	}

	return (count);
}


/**
 * handlers_di - Handles the conversion specifiers 'd' and 'i'
 * @args: Variadic arguments list containing the integer to print
 * Return: The number of characters printed
 */
int handlers_di(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;
	char buffer[20];
	int i = 0;

	if (n < 0) /* Handle negative numbers */
	{
		count += _putchar('-'); /* Prints '-' before negative numbers */
		num = -n; /* Convert to positive for printing */
	}
	else
	{
		num = n; /* Handles regular numbers */
	}
	do {
		buffer[i++] = (num % 10) + '0'; /* Get the last digit */
		num /= 10; /* Remove the last digit */
	} while (num > 0);
	/* Print the digits in the correct order */
	while (i--)
	{
		count += _putchar(buffer[i]);
	}
	return (count);
}
