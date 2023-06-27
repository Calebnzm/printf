#include "main.h"
#include <unistd.h>

/**
 * printf_int - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */
int printf_int(va_list args)
{
	int n = va_arg(args, int);
	int num = n; /* Store the absolute value of n */
	int digit, exp = 1; /* Variables for digit extraction and place value */
	int is_negative = 0; /* Flag to track if the number is negative */
	char c;
	int i; /* Counter for characters printed */

	if (n < 0)
	{
		is_negative = 1;
		num = -num; /* Make num positive for digit extraction */
	}

	/* Calculate the place value of the leftmost digit */
	while (num / 10 != 0)
	{
		exp *= 10;
		num /= 10;
	}

	i = is_negative + 1; /* Increment i to account for negative sign */
	if (is_negative)
		write(1, "-", 1); /* Print '-' if the number is negative */

	num = n;
	while (exp > 0)
	{
		digit = num / exp; /* Extract the leftmost digit */
		c = digit + '0';
		write(1, &c, 1); /* Write the character to stdout */
		num %= exp; /* Remove the leftmost digit from num */
		exp /= 10; /* Decrement the place value */
		i++; /* Increment character count */
	}

	return (i); /* Return the number of characters printed */
}
