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
	int n = va_arg(args, int);
	unsigned int num;
	int lenght = 0;

	if (n < 0)
	{
		putchar('-');
		lenght++;
		num = -n;
	}
	else
	{
		num = n;
	}

	lenght += print_number(num);

	return (lenght);
}
