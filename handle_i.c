#include "main.h"
#include <unistd.h>

/**
 * printf_int - prints an integer
 * @args: argument to print
 *
 * Return: number of characters printed
 */
int printf_int(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		write(1, "-", 1);
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			write(1, &digit, 1);
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	write(1, &last, 1);

	return (i);
}

/**
 * printf_dec - prints a decimal
 * @args: argument to print
 *
 * Return: number of characters printed
 */
int printf_dec(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit;
	int i = 1;
	int exp = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		write(1, "-", 1);
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			write(1, &digit, 1);
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	write(1, &last, 1);

	return (i);
}
