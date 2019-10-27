#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"

/**
* printchar - function that print a char
* @argumentos : type of argument
*/
void printchar(va_list argumentos)
{
	char st;

	st = (char) va_arg(argumentos, int);
	_putchar(st);
}

/**
* printstring - function that print a string
* @argumentos : type of argument
*/

void printstring(va_list argumentos)
{
	char *st;
	int i = 0;

	st = va_arg(argumentos, char *);

	if (st == NULL)
		st = "(null)";
	while (st[i] != '\0')
	{
		_putchar(st[i]);
		i++;
	}
}

/**
* printint - function that print a int
* @argumentos : type of argument
*/

void printint(va_list argumentos)
{
	int n, a, b, c, d, s[1000000];

	n = va_arg(argumentos, int);
	if (n < 0)  /*si el número es negativo*/
	{
		_putchar('-');
		n = n * -1; /*multiplico por -1 para poder quitar el signo*/
	}
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
	}
}
