#include "main.h"

/**
 * handlers_c - Handles the %c format specifier for characters.
 * @args: The list of variable arguments passed to _printf.
 *
 * Return: The number of characters printed.
 */
int handlers_c(va_list args)
{
	int count = 0;
	char c = va_arg(args, int);

	/* If the character is null, print '0' */
	if (c == 0)
	{
		c = '0';
		count += _putchar(c);
		return (0);
	}
	else
	{
		/* Print the character */
		count += _putchar(c);
	}

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

	/* If the string is NULL, use "(null)" */
	if (!p)
	{
		p = "(null)";
		while (*p)
		{
			count += _putchar(*p);
			p++;
		}
		return (0);
	}

	else
	{
		/* Loop through the string and print each character */
		while (*p)
		{
			count += _putchar(*p);
			p++;
		}
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
		count += _putchar('-');
		num = -n; /* Convert to positive for printing */
	}
	else
	{
		num = n;
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

