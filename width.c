#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @i: Index of the current character in the format string
 * @list: va_list of arguments
 * Return: Width w
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_z;
	int w = 0;

	for (curr_z = *i + 1; format[curr_z] != '\0'; curr_z++)
	{
		if (is_digit(format[curr_z]))
		{
			w *= 10;
			w += format[curr_z] - '0';
		}

		else if (format[curr_z] == '*')
		{
			curr_z++;

			w = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = curr_z - 1;
	return (w);
}
