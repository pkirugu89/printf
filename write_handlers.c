#include "main.h"

/* CHAR */

/**
 * handle_write_char - Prints a character
 * @c: char to be printed
 * @buffer: Buffer array to handle print
 * @flags: Calculated active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = 0;
	char pd = ' ';
	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pd = '0';

	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';

		for (x = 0; x < width - 1; x++)
			buffer[BUFF_SIZE - x - 2] = pd;

		if (flags & F_MINUS)
			return (_putchar(buffer[0]) + _putchar(buffer[BUFF_SIZE - x - 1]) + width - 1);
		else
			return (_putchar(buffer[BUFF_SIZE - x - 1]) + _putchar(buffer[0]) + width - 1);
	}
	return (_putchar(buffer[0]));
}

/* NUMBER */

/**
 * write_number - Prints a number
 * @is_negative: Number indicating if the number is negative
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer array to handle print
 * @flags: Calculated active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char pd = ' ', extra_ch = 0;
	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pd = '0';

	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision, len, pd, extra_ch));
}

/**
 * write_num - Write a number using a buffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer array
 * @flags: Flags specifier
 * @width: Width specifier
 * @precision: Precision specifier
 * @length: Number length
 * @padd: Padding character
 * @extra_ch: Extra character
 *
 * Return: Number of characters printed
 */
int write_num(int ind, char buffer[],
		int flags, int width, int precision, int length, char padd, char extra_ch)
{
	int y, padd_start = 1;
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
        return (0);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
	{
		buffer[ind] = padd = ' ';
	}

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
		buffer[--ind] = '0', length++;

	if (extra_ch != 0)
		length++;

	if (width > length)
	{
		for (y = 1; y < width - length + 1; y++)
			buffer[y] = padd;

		buffer[y] = '\0';

		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_ch)
				buffer[--ind] = extra_ch;
			_putchar(buffer[ind]);
			_putchar(buffer[0]);

			return (length + y);
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_ch)
				buffer[--ind] = extra_ch;

			_putchar(buffer[0]);
			_putchar(buffer[ind]);

			return (length + y);
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_ch)
				buffer[--padd_start] = extra_ch;

			_putchar(buffer[padd_start]);

			for (y = padd_start + 1; y <= length; y++)
				_putchar(buffer[y]);

			return (length);
		}
	}

	if (extra_ch)
		buffer[--ind] = extra_ch;

	for (y = ind; y < BUFF_SIZE; y++)
		_putchar(buffer[y]);

	return (length);
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the number is negative
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer array
 * @flags: Flags specifier
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, y = 0;
	char pd = ' ';
	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		pd = ' ';

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pd = '0';

	if (width > len)
	{
		for (y = 0; y < width - len; y++)
			buffer[y] = pd;

		buffer[y] = '\0';

		if (flags & F_MINUS)
		{
			_putchar(buffer[ind]);
			_putchar(buffer[0]);
			return (len + y);
		}
        else
	{
		_putchar(buffer[0]);
		_putchar(buffer[ind]);
		return (len + y);
        }
	}

	for (y = ind; y < BUFF_SIZE; y++)
		_putchar(buffer[y]);

	return (len);
}

/**
 * write_pointer - Write a memory address
 * @buffer: Buffer array
 * @ind: Index at which the number starts on the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Padding character
 * @extra_ch: Extra character
 * @padd_start: Index at which padding should start
 *
 * Return: Number of characters printed
 */
int write_pointer(char buffer[], int ind, int length, int width,
		int flags, char padd, char extra_ch, int padd_start)
{
	int y;

	if (width > length)
	{
		for (y = 3; y < width - length + 3; y++)
			buffer[y] = padd;

		buffer[y] = '\0';

		if (flags & F_MINUS && padd == ' ')
		{
			_putchar('0');
			_putchar('x');
			_putchar(buffer[ind]);

			return (length + y);
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			_putchar('0');_putchar('x');
			_putchar(buffer[3]);
			
			return (length + y);
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_ch)
				buffer[--padd_start] = extra_ch;

			_putchar(buffer[padd_start]);

			for (y = padd_start + 1; y <= length + 2; y++)
				_putchar(buffer[y]);

			return (length + 2);
		}
	}
	_putchar('0');
	_putchar('x');

	for (y = ind; y < BUFF_SIZE; y++)
		_putchar(buffer[y]);

	return (length);
}
