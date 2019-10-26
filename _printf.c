#include <stdio.h>
#include "holberton.h"
#include <stdarg.h>

void printchar(va_list argumentos)
{
	int st;
	st = va_arg(argumentos, int);
	_putchar(st);
}
void printstring(va_list argumentos)
{
	char *st;

	st = va_arg(argumentos, char *);
	printf("%s", st);
}

int _printf(const char *format, ...)
{
	va_list argumentos;
	int i = 0, j;

	op_t ops[] = {
		{"c", printchar},
		{"s", printstring},
		{NULL, NULL}
	};
	va_start(argumentos, format);

	/* recorrer format */
	while (format[i])
	{
		if (format[i] == 92)
		{
			if (format[i + 1] == 32 || format[i + 1] == 92 || format[i + 1] == 37)
			{
				_putchar(format[i]);
				i++;
			}
		}
		if (format[i] == 37)
		{
			j = 0;
			while (ops[j].op != NULL)
			{
				if (format[i + 1] == *(ops[j].op))
				{
					(ops[j].f)(argumentos);
					i = i + 2;
					break;
				}
				j++;
			}
		}
		_putchar(format[i]);
		i++;
	}
	
	return (i);
}

int main()
{

	_printf("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	return(0);
}
