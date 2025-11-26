#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
/**
 * struct checker - structure to map format specifiers to functions
 *
 * @type: format specifier character
 * @func: pointer to the function that handles the format specifier
 *
 */
typedef struct checker
{
	char *type;
	int (*func)(va_list args);
} checker_t;

int print_char(va_list args);
int print_percent(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
int print_float(va_list args);
int _printf(const char *format, ...);

#endif
