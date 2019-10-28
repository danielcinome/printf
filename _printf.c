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
	int i = 0, j = 0, c = 0, d = 0;

	op_t ops[] = {{"c", printchar}, {"s", printstring},
	{"i", printint}, {"d", printint}, {NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(argumentos, format);
	if (argumentos == NULL)
		return (-1);

	while (format[i]) /* recorrer format */
	{
		if (format[i] == 37)
		{
			if (format[i + 1] != 37) /*Si el caracter siguiente no es %*/
			{
				while (ops[j].op != NULL)
				{
					if (format[i + 1] == *(ops[j].op))
					{
						c = (ops[j].f)(argumentos);
						i = i + 2;
						break;
					}
					j++;
					if (ops[j].op == NULL)
						return (-1);
				}

			}
			if (format[i + 1] == 37) /*si el caracter siguiente es % avanzo 1 pos*/
				i++;
		}
		_putchar(format[i]);
		i++;
		d++;
	}
	va_end(argumentos);
	return (d + c);
}
