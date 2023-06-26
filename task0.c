#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
* _printf - writes to stdout
* @format: the fomat of whatever is to be written
*
* Return: characters printed to the stdout
*/
int _printf(const char *format, ...)
{
va_list args;
char bufferr[32], buffer[12];
int length, int_to_print;
const char *string_to_print;
double float_to_print;
int characters_printed = 0;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
	format++;
	switch (*format)
	{
	case 's':
	{
	string_to_print = va_arg(args, const char *);
	characters_printed += write(1, string_to_print, strlen(string_to_print));
	break;
	}
	case 'd':
	{
	int_to_print = va_arg(args, int);
	characters_printed += snprintf(buffer, sizeof(buffer), "%d", int_to_print);
	break;
	}
	case 'f':
	{
	float_to_print = va_arg(args, double);
	length = snprintf(bufferr, sizeof(bufferr), "%f", float_to_print);
	characters_printed += write(1, bufferr, length);
	break;
	}
	default:
	{
	break;
	}
	}
}
else
{
	characters_printed += write(1, format, 1);
}
format++;
}
va_end(args);
return (characters_printed);
}
