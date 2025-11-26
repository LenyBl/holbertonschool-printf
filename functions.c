#include "main.h"
/**
 * print_char - prints a character
 *
 * @args: va_list containing the character to print
 *
 * Return: 1 (number of characters printed)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	putchar(c);
	return (1);
}
/**
 * print_percent - prints a percent sign
 *
 * @args: va_list containing the percent sign to print
 *
 * Return: 1 (number of characters printed)
 */
int print_percent(va_list args)
{
	(void)args;
	putchar('%');
	return (1);
}
/**
 * print_string - prints a string
 *
 * @args: va_list containing the string to print
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int length = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		putchar(*str);
		str++;
		length++;
	}

	return (length);
}
/**
 * print_integer - prints an integer
 *
 * @args: va_list containing the integer to print
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
	int num = va_arg(args, int);
	char buffer[12];
	int length = 0;
	int i = 0, j;

	if (num == 0)
	{
		putchar('0');
		length++;
		return (length);
	}

	if (num < 0)
	{
		putchar('-');
		num = -num;
		length++;
	}

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
		length++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		putchar(buffer[j]);
	}

	return (length);
}
/**
 * print_float - prints a floating-point number
 *
 * @args: va_list containing the float to print
 *
 * Return: Number of characters printed
 */
int print_float(va_list args)
{
	double num = va_arg(args, double);
	int int_part = (int)num;
	int length = 0;
	double frac_part = num - int_part;
	int i, j;
	char buffer[20];
	int digit;
	
	if (num < 0)
	{
		putchar('-');
		int_part = -int_part;
		frac_part = -frac_part;
		length++;
	}

	if (int_part == 0)
	{
		putchar('0');
		length++;
	}
	else
	{
		i = 0;
		while (int_part > 0)
		{
			buffer[i++] = (int_part % 10) + '0';
			int_part /= 10;
			length++;
		}
		for (j = i - 1; j >= 0; j--)
		{
			putchar(buffer[j]);
		}
	}

	putchar('.');
	length++;

	for (i = 0; i < 6; i++)
	{
		frac_part *= 10;
		digit = (int)frac_part;
		putchar(digit + '0');
		length++;
		frac_part -= digit;
	}
	return (length);
}
