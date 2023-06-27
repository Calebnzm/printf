#ifndef MAIN_H
#define MAIN_H

#define BUFF_SIZE 1024
void int_to_str(int num, char buffer[], int *buff_ind);
void reverse_str(char str[], int len, int *buff_ind, char buffer[]);
#include <limits.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

#endif
