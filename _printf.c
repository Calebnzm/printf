#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int i;
    char buffer[BUFF_SIZE];
    int buff_ind = 0;
    int printed_chars = 0;
    int len;
    char *str;
    int c;

    va_list args;
    va_start(args, format);


	if (format == NULL)
        return -1;
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE - 1)
            {
                buffer[buff_ind] = '\0';
                write(1, buffer, buff_ind);
                printed_chars += buff_ind;
                buff_ind = 0;
            }
        }
        else
        {
            buffer[buff_ind] = '\0';
            write(1, buffer, buff_ind);
            printed_chars += buff_ind;
            buff_ind = 0;

            i++;

            /* Process format specifier */
            switch (format[i])
            {
                case 'c':
                    {
                        c = va_arg(args, int);
                        write(1, &c, 1);
                        printed_chars++;
                        break;
                    }
                case 's':
                    {
                        str = va_arg(args, char *);
                        if (str == NULL)
                            str = "(null)";
                        len = strlen(str);
                        write(1, str, len);
                        printed_chars += len;
                        break;
                    }

                default:
                    write(1, &format[i], 1);
                    printed_chars++;
                    break;
            }
        }
    }

    buffer[buff_ind] = '\0';
    write(1, buffer, buff_ind);
    printed_chars += buff_ind;

    va_end(args);

    return printed_chars;
}

/**
 * print_buffer - Writes the buffer to standard output
 * @buffer: The buffer containing the characters to print
 * @buff_ind: The current index in the buffer
 */
void print_buffer(char buffer[], int *buff_ind)
{
    buffer[*buff_ind] = '\0';
    write(1, buffer, *buff_ind);
    *buff_ind = 0;
}
