#include "main.h"

/************************* PRINT CHAR *************************/
/**
* print_char - Prints a char
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
* print_string - Prints a string
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int length = 0, s;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			for (s = 0; s < length; s++)
				_putchar(str[s]);
			for (s = width - length; s > 0; s--)
				_putchar(' ');
			return (width);
		}
		else
		{
			for (s = width - length; s > 0; s--)
				_putchar(' ');
			for (s = 0; s < length; s++)
				_putchar(str[s]);
			return (width);
		}
	}
	for (s = 0; s < length; s++)
		_putchar(str[s]);
	return (length);
}
/************************* PRINT PERCENT SIGN *************************/
/**
* print_percent - Prints a percent sign
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	_putchar('%');
	return (1);
}
/************************* PRINT INT *************************/
/**
* print_int - Print int
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	int is_negative = 0;
	long int sz = va_arg(types, long int);
	unsigned long int num;

	sz = convert_size_number(sz, size);

	if (sz == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)sz;

	if (sz < 0)
	{
		num = (unsigned long int)((-1) * sz);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[y--] = (num % 10) + '0';
		num /= 10;
	}

	y++;

	return (write_number(is_negative, y, buffer, flags, width, precision, size));
}
/************************* PRINT BINARY *************************/
/**
* print_binary - Prints an unsigned number
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	unsigned int o, p, y, sum;
	unsigned int b[32];
	int cnt;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	o = va_arg(types, unsigned int);
	p = 2147483648; /* (2 ^ 31) */
	b[0] = o / p;

	for (y = 1; y < 32; y++)
	{
		p /= 2;
		b[y] = (o / p) % 2;
	}

	for (y = 0, sum = 0, cnt = 0; y < 32; y++)
	{
		sum += b[y];
		if (sum || y == 31)
		{
			_putchar('0' + b[y]);
			cnt++;
		}
	}

	return (cnt);
}
