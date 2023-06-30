#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Index of the current character in the format string
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int y, curr_z;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_z = *i + 1; format[curr_z] != '\0'; curr_z++)
	{
		for (y = 0; FLAGS_CH[y] != '\0'; y++)
		{
			if (format[curr_z] == FLAGS_CH[y])
			{
				flags |= FLAGS_ARR[y];
				break;
			}
		}

		if (FLAGS_CH[y] == 0)
			break;
	}

	*i = curr_z - 1;
	return (flags);
}
