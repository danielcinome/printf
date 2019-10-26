#include <stdio.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	int i = 0;

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
		_putchar(format[i]);
		i++;
	}
	
	return (i);
}
