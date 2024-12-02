#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Format string containing the characters and the specifiers
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (!format)
	{
		return (-1);
	}
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_specifier(format, args);
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
