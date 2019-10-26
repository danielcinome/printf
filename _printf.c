#include <stdio.h>
#include "holberton.h"

int _printf(const char *format, ...)
{
	int i = 0;

	while (format[i])
	{
		if (format[i] == 92)
		{
			if (format[i + 1] == 32 || format[i + 1] == 92 || format[i + 1] == 37)
			{
				i++;
				_putchar(format[i]);
			}
		}
		_putchar(format[i]);
		i++;
	}
	
	return (i);
}

int main(void)
{

    _printf("Let's try to printf a simple sentence.\n");
    printf("Let's try 1 to printf a simple sentence.\n");

    return (0);
}
