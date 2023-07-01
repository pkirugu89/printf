#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: Index of the current character in the format string
 * Return: Size sz
 */
int get_size(const char *format, int *i)
{
	int curr_z = *i + 1;
	int sz = 0;

	if (format[curr_z] == 'l')
		sz = S_LONG;

	else if (format[curr_z] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*i = curr_z - 1;

	else
		*i = curr_z;

	return (sz);
}
