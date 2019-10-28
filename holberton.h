#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <stdio.h>

/**
* struct op - Struct
* @op: type of data
* @f: call function
*/

typedef struct op
{
	char *op;
	int (*f)(va_list);
} op_t;

int _putchar(char c);
int _printf(const char *format, ...);
void op(char format);

int printchar(va_list argumentos);
int printstring(va_list argumentos);
int printint(va_list argumentos);


#endif

