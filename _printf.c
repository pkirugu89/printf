#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
	int y, printed = 0, printed_count = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list l;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(l, format);

	for (y = 0; format && format[y] != '\0'; y++)
	{
		if (format[y] != '%')
		{
			buffer[buff_ind++] = format[y];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_count++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &y);
			width = get_width(format, &y, l);
			precision = get_precision(format, &y, l);
			size = get_size(format, &y);
			++i;
			printed = handle_print(format, &y, l, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_count += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(l);

	return (printed_count);
}

/**
* print_buffer - Prints the contents of the buffer if it exists
* @buffer: Array of chars
* @buff_ind: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		for (int i = 0; i < *buff_ind; i++)
		{
			_putchar(buffer[i]);
		}
	}
	*buff_ind = 0;
}

