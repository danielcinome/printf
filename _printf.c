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
	int i = 0;

	st = va_arg(argumentos, char *);
	while (st[i] != '\0')
	{
		_putchar(st[i]);
		i++;
	}
}

void printint(va_list argumentos)
{
	int n, a, b, c, d, s[1000000];
	
	n = va_arg(argumentos, int);

	d = 0;
	a = n / 10;
	b = n % 10;
	if (a <= 9)
	{
		s[0] = b;
		s[1] = a;
		_putchar(s[1] + '0');
		_putchar(s[0] + '0');
	}
	else
	{
		while (n > 9)
		{
			b = n % 10;
			n = n / 10;
			s[d] = b;
			if (n <= 9)
			{
				s[d + 1] = n;
			}
			++d;
		}
		for (c = d ; c >= 0 ; c--)
		{
			_putchar(s[c] + '0');
		}
//		_putchar('\n');
	}
}

int _printf(const char *format, ...)
{
	va_list argumentos;
	int i = 0, j;

	op_t ops[] = {
		{"c", printchar},
		{"s", printstring},
		{"i", printint},
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
	int len;
    	int len2;
	len = 350000;
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Length:[%i]\n", len);
    	printf("Length:[%i]\n", len2);
	return(0);
}
