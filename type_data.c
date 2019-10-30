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
	int a[10];
	int j, m, n, sum, d;

	n = va_arg(i, int);
	d = 0;
	m = 1000000000;
	a[0] = n / m;
	for (j = 1; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	if (n < 0)
	{
		_putchar('-');
		d++;
		for (j = 0; j < 10; j++)
			a[j] *= -1;
	}
	for (j = 0, sum = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum != 0 || j == 9)
		{
			_putchar('0' + a[j]);
			d++;
		}
	}
	return (d);
}
