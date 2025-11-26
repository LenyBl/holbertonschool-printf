#include "main.h"
/**
 * _printf - custom implementation of printf
 *
 * @format: format string containing characters and format specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int indexFormat = 0;
	int indexPrinter;
	int recognized_format;
	int lenght;
	char bufferFormat[3];

	va_list listArgs;
	va_start(listArgs, format);

	checker_t printerStockage[] = {
		{"%c", print_char},
		{"%i", print_integer},
		{"%d", print_float},
		{"%s", print_string},
		{"%%", print_percent},
		{"", NULL}};

	if (format == NULL)
		return (-1);

	while (format[indexFormat] != '\0')
	{
		if (format[indexFormat] == '%')
		{
			recognized_format = 0;
			indexPrinter = 0;

			while (printerStockage[indexPrinter].type[0] != '\0')
			{
				bufferFormat[0] = format[indexFormat];
				bufferFormat[1] = format[indexFormat + 1];
				bufferFormat[2] = '\0';

				if (strcmp(bufferFormat, printerStockage[indexPrinter].type) == 0)
				{
					lenght += printerStockage[indexPrinter].func(listArgs);
					recognized_format = 1;
					indexFormat += 2;
					break;
				}
				indexPrinter++;
			}

			if (!recognized_format)
			{
				putchar('%');
				putchar(format[indexFormat + 1]);
				lenght += 2;
				indexFormat += 2;
			}
		}
		else
		{
			putchar(format[indexFormat]);
			lenght++;
			indexFormat++;
		}
	}

	va_end(listArgs);
	return (lenght);
}
