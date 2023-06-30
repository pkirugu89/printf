#include "main.h"

/****************** PRINT POINTER ******************/

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_ch = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long n_adrs;
	char map_to[] = "0123456789abcdef";
	void *adrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);
	if (adrs == NULL)
		return (_putchar('(') + _putchar('n') +
				_putchar('i') + _putchar('l') + _putchar(')'));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	n_adrs = (unsigned long)addrs;
	while (n_adrs > 0)
	{
		buffer[ind--] = map_to[n_adrs % 16];
		n_adrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_ch = '+', length++;
	else if (flags & F_SPACE)
		extra_ch = ' ', length++;
	ind++;
	return (write_pointer(buffer, ind, length,
				width, flags, padd, extra_ch, padd_start));
}
/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable-Prints ASCII codes in hexadecimal of non-printable chars
 * @types:List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int y = 0, ofset = 0;
	char *strs = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (strs == NULL)
		return (_putchar('(') + _putchar('n') + _putchar('u') +
				_putchar('l') + _putchar('l') + _putchar(')'));
	while (strs[y] != '\0')
	{
		if (is_printable(str[y]))
			buffer[y + ofset] = strs[y];
		else
			offset += append_hexa_code(strs[y], buffer, y + ofset);
		y++;
	}
	buffer[y + ofset] = '\0';
	return (write(1, buffer, y + ofset));
}

/************************* PRINT REVERSE *************************/

/**
 * print_reverse - Prints a reverse string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *strs;
	int y, cnt = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	strs = va_arg(types, char *);
	if (strs == NULL)
	{
		UNUSED(precision);
		strs = ")Null(";
	}
	for (y = 0; strs[y]; y++)
		;
	for (y = y - 1; y >= 0; y--)
	{
		char z = strs[y];

		_putchar(z);
		cnt++;
	}
	return (cnt);
}

/************************* PRINT A STRING IN ROT13 *************************/

/**
 * print_rot13string - Prints a string in ROT13.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *strs;
	unsigned int y, z;
	int cnt = 0;
	char in[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	strs = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (strs == NULL)
		strs = "(AHYY)";
	for (y = 0; str[y]; y++)
	{
		for (z = 0; in[z]; z++)
		{
			if (in[z] == str[y])
			{
				x = out[z];
				_putchar(x);
				cnt++;
				break;
			}
		}
		if (!in[z])
			x = str[y];
		_putchar(x);
		cnt++;
	}
	return (cnt);
}
