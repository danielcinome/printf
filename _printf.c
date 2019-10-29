#include "holberton.h"
#include <stdlib.h>

/**
* get_op_func - unction that selects the correct
* function to perform the operation asked by the system.
* @format: format read
* Return: result of operation
*/

int (*get_op_func(const char *format))(va_list)
{
	op_t ops[] = {
	{"c", printchar},
	{"s", printstring},
	{"i", printint},
	{"d", printd},
	{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op != NULL)
	{
		if (*ops[i].op == *format)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

/**
* _printf - function that produces output according to a format.
* @format : type of format for print
* Return: length of string
*/

int _printf(const char *format, ...)
{
	int i = 0, d = 0, flag = 0;
	va_list argumentos;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(argumentos, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			d++;
		}
		if (format[i] == '%' || flag == 1)
		{
			d++;
			f = get_op_func(&format[i + 1]);
			if (f != NULL)
			{
				d = d + f(argumentos);
				i++;
				flag = 0;
			}
			if (f == NULL && format[i + 1] != 32)
			{
				_putchar(format[i + 1]);
				i++;
				flag = 0;
			}
			else
				flag = 1;
		}
		i++;
	}
	va_end(argumentos);
	return (d);
}

