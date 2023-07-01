#include "main.h"
#include <unistd.h>

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments
 * @list: List of arguments to be printed
 * @ind: Index of the current character in the format string
 * @buffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of characters printed
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int y, un_len = 0, printed_count = -1;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (y = 0; fmt_types[y].fmts != '\0'; y++)
	{
		if (fmt[*ind] == fmt_types[y].fmts)
			return (fmt_types[y].fn(list, buffer, flags, width, precision, size));
	}

	if (fmt_types[y].fmts == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);

		un_len += _putchar('%');

		if (fmt[*ind - 1] == ' ')
			un_len += _putchar(' ');

		else if (width)
		{
			--(*ind);

			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);

			if (fmt[*ind] == ' ')
				--(*ind);

			return (1);
		}

		un_len += _putchar(fmt[*ind]);

		return (un_len);
	}

	return (printed_count);
}
