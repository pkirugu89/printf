#include <unistd.h>
#include "main.h"
/**
 * print_char - function to print characters
 * @fp: file descriptor
 * @c: characters to print
 * Return:Printed chars.
 */
int print_char(int fp, char c)
{
	return (write(fp, &c, 1));
}
/**
 * print_string - function to print strings
 * @fp: file descriptor
 * @str: string to print
 * Return: String length.
 */
int print_string(int fp, const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		write(fp, &str[length], 1);
		length++;
	}
	return (length);
}
/**
 * print_percent - function to print percent sign
 * @fp: file descriptor
 * Return: Printed chars.
 */
int print_percent(int fp)
{
	char c = '%';

	return (write(fp, &c, 1));
}
/**
 * print_int - function to print integers
 * @fp: file descriptor
 * @num: integers to print
 * Return: Printed integers.
 */
int print_int(int fp, int num)
{
	int ds = 0;
	int tmp = num;
	/* Count the number of digits in the number */
	if (tmp == 0)
	{
		ds = 1;
	}
	else
	{
		while (tmp != 0)
		{
			tmp /= 10;
			ds++;
		}
	}
	/* Handle negative numbers */
	if (num < 0)
	{
		write(fp, "-", 1);
		num = -num;
	}
	/* Print the digits in reverse order */
	while (ds > 0)
	{
		int d = num % 10;
		char c = '0' + d;

		write(fp, &c, 1);
		num /= 10;
		ds--;
	}
	return (ds);
}

