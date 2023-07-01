#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Index of the current character in the format string
 * @list: List of arguments
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_z = *i + 1;
	int p = -1;

	if (format[curr_z] != '.')
		return (p);

	p = 0;

	for (curr_z += 1; format[curr_z] != '\0'; curr_z++)
	{
		if (is_digit(format[curr_z]))
		{
		p *= 10;
		p += format[curr_z] - '0';
		}

		else if (format[curr_z] == '*')
		{
			curr_z++;
			p = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = curr_z - 1;

	return (p);
}
