#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <stdio.h>

typedef struct op
{
	char *op;
	void (*f)(va_list);
} op_t;

int _putchar(char c);
int _printf(const char *format, ...);

void printchar(va_list argumentos);
void printstring(va_list argumentos);
void printint(va_list argumentos);

#endif

