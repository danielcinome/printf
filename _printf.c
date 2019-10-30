#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"

/**
* _printf - function that produces output according to a format.
* @format : type of format for print
* Return: length of string
*/

int _printf(const char *format, ...)
{
	va_list argumentos;
	int i = 0, j = 0, c = 0, d = 0, a = 0, cont = 0;

	op_t ops[] = {{"c", printchar}, {"s", printstring},
	{"i", printint}, {"d", printint}, {"b", bin}, {NULL, NULL}
	};
	if (format == NULL || argumentos == NULL)
		return (-1);
	va_start(argumentos, format);
	while (format && format[i]) /* recorrer format */
	{
		if (format[i] == 37 || a == 1)
		{
			if (format[i] == 37 && format[i + 1] == '\0')
				return (-1);
			if (a != 1)
				i++;
			if (format[i] != 37) /*Si el caracter siguiente no es %*/
			{	j = 0;
				a = 1;
				while (ops[j].op != NULL)
				{
					if (format[i] == *(ops[j].op))
					{	c = (ops[j].f)(argumentos);
						cont = cont + c;
						a = 2;
						break;
					}
					j++;
				}
				if (format[i] != 32 && a != 2)
				{	a = 0;
					/*if (format[i + 1] != 37)*/
						d++;
						_putchar(37);
					if (format[i - 1] == 32)
					{	d++;
						_putchar(32);
					}
				}
			}
			if (format[i] == 37) /*si el caracter siguiente es % avanzo 1 pos*/
				a = 0;
		}
		if (a == 0)
		{	_putchar(format[i]);
			d++;
		}
		i++;
		if (a == 2)
			a = 0;
	}
	va_end(argumentos);
	return (d + cont);
}
