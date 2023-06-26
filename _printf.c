#include "main.h"


int _printf(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    int characters_printed = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 's':
                {
                    const char* string_to_print = va_arg(args, const char*);
                    size_t length = strlen(string_to_print);
                    ssize_t bytes_written = write(1, string_to_print, length);
                    if (bytes_written > 0)
                        characters_printed += bytes_written;
                    break;
                }
                case 'd':
                {
                    int int_to_print = va_arg(args, int);
                    char buffer[12];
                    ssize_t bytes_written = snprintf(buffer, sizeof(buffer), "%d", int_to_print);
                    if (bytes_written > 0)
                    {
                        bytes_written = write(1, buffer, bytes_written);
                        if (bytes_written > 0)
                            characters_printed += bytes_written;
                    }
                    break;
                }
                case 'f':
                {
                    double float_to_print = va_arg(args, double);
                    char buffer[32];
                    ssize_t bytes_written = snprintf(buffer, sizeof(buffer), "%f", float_to_print);
                    if (bytes_written > 0)
                    {
                        bytes_written = write(1, buffer, bytes_written);
                        if (bytes_written > 0)
                            characters_printed += bytes_written;
                    }
                    break;
                }
                default:
                {
                    // Ignore unrecognized specifiers
                    break;
                }
            }
        }
        else
        {
            ssize_t bytes_written = write(1, format, 1);
            if (bytes_written > 0)
                characters_printed += bytes_written;
        }

        format++;
    }

    va_end(args);
    return characters_printed;
}
