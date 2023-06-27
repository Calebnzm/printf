#include "main.h"

/**
 * printf_dec - Prints a decimal number
 * @args: Argument to print
 *
 * Return: Number of characters printed
 */
int printf_dec(va_list args)
{
	int n = va_arg(args, int);
	int digit_count = 0;
	int digit;
	char ch;
	int num;
	int exp;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		digit_count++;
	}

	if (n == 0)
	{
		write(1, "0", 1);
		digit_count++;
	}
	else
	{
		num = n;
		exp = 1;

		/* Calculate the number of digits */
		while (num > 0)
		{
			num /= 10;
			exp *= 10;
		}

		/* Print each digit */
		while (exp > 1)
		{
			exp /= 10;
			digit = n / exp;
			ch = digit + '0';
			write(1, &ch, 1);
			n %= exp;
			digit_count++;
		}
	}

	return (digit_count);
}
