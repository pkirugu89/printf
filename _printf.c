#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function to print formatted output
 * @format: method argument.
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	va_list l; /* l is a variable of va_list */

	va_start(l, format);

	int print_out = 0;
	const char *pt = format;

	while (*pt != '\0')
		if (*pt != '%')
			write(1, pt, 1);
			print_out++;
		else
		{
			pt++;
			if (*pt == '%')
				write(1, pt, 1);
				print_out++;
			else if (*pt == 'c')
				char c = va_arg(l, int);

				print_out += print_char(1, c);
			else if (*pt == 's')
				char *str = va_arg(l, char*);

				if (str == NULL)
					str = "(null)";
				print_out += print_string(1, str);
			else if (*pt == 'd' || *pt == 'i')
				int num = va_arg(l, int);

				print_out += print_int(1, num);
			else if (*pt == '%')
				print_out += print_percent(1);
		}
	pt++;

	va_end(l);

	return (print_out);
}
