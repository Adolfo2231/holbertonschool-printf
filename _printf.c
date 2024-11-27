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
		format = "(null)";
		while (*format)
		{
			count += _putchar(*format);
			format++;
		}
		_putchar('\n');
		return (0);
	}
	while (*format)
	{
		if (*format == '%') /* Identifica un especificador */
		{
			format++;
			switch (*format)
			{
				case 'c': /* Especificador %c */
					count += handlers_c(args);
					break;
				case 's':/* Especificador %s */
					count += handlers_s(args);/* Manage strings*/
					break;
				default: /* Especificador desconocido */
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else /* Imprime texto literal */
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count); /* Conteo de caracteres */
}
