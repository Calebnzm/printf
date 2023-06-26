#include <stdarg.h>
#include <unistd.h> // for write
#include <stdio.h>

/**
 * _printf - Custom printf function that produces output according to a format
 * @format: The format string containing zero or more directives
 * @...: Additional arguments to be formatted according to the format string
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int printed_chars = 0;
	char c;
	const char *s;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(STDOUT_FILENO, &c, 1);
					printed_chars++;
					break;
				case 's':
					s = va_arg(args, const char *);
					while (*s != '\0')
					{
						write(STDOUT_FILENO, s, 1);
						s++;
						printed_chars++;
					}
					break;
				case '%':
					write(STDOUT_FILENO, "%", 1);
					printed_chars++;
					break;
				default:
					write(STDOUT_FILENO, "%", 1);
					write(STDOUT_FILENO, format, 1);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			printed_chars++;
		}
		format++;
	}

	va_end(args);

	return printed_chars;
}
