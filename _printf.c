#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	va_list argumentos;
	int i = 0, j;
	int d = 0;

	op_t ops[] = {
		{"c", printchar},
		{"s", printstring},
		{"i", printint},
		{"d", printint},
		{NULL, NULL}
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
			j = 0;
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
	return (i - d);
}
