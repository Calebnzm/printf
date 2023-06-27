#include "main.h"

/**
* int_to_str - changes integer to string
* @num: the num to be written
* @buffer: the buffer
* @buff_ind: the buff_ind
*
* Return: abs..
*/
void int_to_str(int num, char buffer[], int *buff_ind)
{
int i = 0;
int is_negative = 0;
if (num < 0)
{
	is_negative = 1;
	num = -num;
}
do {
buffer[i++] = (num % 10) + '0';
num /= 10;
} while (num != 0);
if (is_negative)
	buffer[i++] = '-';
reverse_str(buffer, i, buff_ind, buffer);
}

/**
* reverse_str - reverses string
* @str: the string to be reversed
* @len: the length of the string
* @buff_ind: the buff ind
* @buffer: the buffer
*
* Return: chabs
*/
void reverse_str(char str[], int len, int *buff_ind, char buffer[])
{
int i;
int start = 0;
int end = len - 1;
while (start < end)
{
char temp = str[start];
str[start] = str[end];
str[end] = temp;
start++;
end--;
}
for (i = 0; i < len; i++)
{
buffer[(*buff_ind)++] = str[i];
if (*buff_ind == BUFF_SIZE - 1)
{
	buffer[*buff_ind] = '\0';
	write(1, buffer, *buff_ind);
	*buff_ind = 0;
}
}
}
