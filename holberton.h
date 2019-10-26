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
void print_all(const char * const format, ...);

#endif

