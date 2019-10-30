#include "holberton.h"
#include <stdarg.h>

/**
* bin - convert to binary
* @argumentos: number to convert
* Return: len of binary
*/

int bin(va_list argumentos)
{
	int st[1000000];
	int mod, j, i = 0;
	unsigned int n;

	n = va_arg(argumentos, unsigned int);

	if (n == 0)
	{
		_putchar(st[i + 1] == '0');
		i++;
	}

	while (n != 0)
	{
		mod = n % 2;
		n = n / 2;
		st[i] = mod;
		i++;
	}

	for (j = (i - 1) ; j >= 0 ; j--)
	{
		_putchar(st[j] + '0');
	}
	va_end(argumentos);
	return (i);
}
