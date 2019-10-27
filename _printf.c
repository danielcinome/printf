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
	int i = 0, j = 0, d = 0;

	op_t ops[] = {{"c", printchar}, {"s", printstring},
	{"i", printint}, {"d", printint}, {NULL, NULL}
	};
	va_start(argumentos, format);
	while (format[i]) /* recorrer format */
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
			if (format[i + 1] != 37) /*Si el caracter siguiente no es %*/
			{
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
			if (format[i + 1] == 37) /*si el caracter siguiente es % avanzo 1 pos*/
			{
				i++;
				d = d + 1; /* resto lo que me mueva*/
			}
		}
		_putchar(format[i]);
		i++;
	}
	va_end(argumentos);
	return (i - d);
}
