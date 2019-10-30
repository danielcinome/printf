#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"

/**
* printchar - function that print a char
* @argumentos : type of argument
* Return: number of character
*/
int printchar(va_list argumentos)
{
	char st;

	st = (char) va_arg(argumentos, int);
	_putchar(st);
	return (1);
}

/**
* printstring - function that print a string
* @argumentos: type of argument
* Return: number of character
*/

int printstring(va_list argumentos)
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
	return (i);
}

/**
* printint - function that print a int
* @i: type of argument
* Return: number of character
*/

int printint(va_list i)
{
	int n, b, c, d, s[1000000];

	n = va_arg(i, int);

	if (n < 0)  /*si el número es negativo*/
	{
		_putchar('-');
		n = n * -1; /*multiplico por -1 para poder quitar el signo*/
	}
	d = 0;

	if (n <= 9)
	{
		_putchar(n + '0');
		d++;
		return (d);
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
	return (d);
}
