#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/*
 * File: main.h
 * Description: Header file containing prototypes for functions
 *              used in the _printf project. Includes standard
 *              library headers and function prototypes for
 *              formatting and handling variable arguments.
 */

/*
 * Function Prototypes
 */

/**
 * _printf - Produces output according to a format.
 * @format: A string containing the format specifiers.
 *
 * Return: The number of characters printed (excluding the
 *         null byte used to end output to strings).
 */
int _printf(const char *format, ...);

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, 1 is returned.
 *         On error, -1 is returned and errno is set.
 */
int _putchar(char c);

/*
 * Handler Functions
 */

/**
 * handlers_c - Handles the %c format specifier for characters.
 * @args: A list of arguments pointing to the character to print.
 *
 * Return: The number of characters printed.
 */
int handlers_c(va_list args);

/**
 * handlers_s - Handles the %s format specifier for strings.
 * @args: A list of arguments pointing to the string to print.
 *
 * Return: The number of characters printed.
 */
int handlers_s(va_list args);

#endif /* MAIN_H */

