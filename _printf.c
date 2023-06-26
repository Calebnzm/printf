#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	char buffer[BUFF_SIZE];
	int buff_ind = 0;
	int printed_chars = 0;
	va_list args;
	int c;
	char *str;
	int len;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			buffer[buff_ind++] = *format;
			if (buff_ind == BUFF_SIZE - 1)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += buff_ind;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			format++; /* Skip '%' */

			switch (*format)
			{
			case 'c':
				c = va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				len = strlen(str);
				write(1, str, len);
				printed_chars += len;
				break;
			default:
				write(1, format, 1);
				printed_chars++;
				break;
			}
		}

		format++; /* Move to the next character */
	}

	print_buffer(buffer, &buff_ind);
	printed_chars += buff_ind;

	va_end(args);

	return (printed_chars);
}

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		buffer[*buff_ind] = '\0';
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
