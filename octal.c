#include "holberton.h"
#include <stdarg.h>

/**
* print_oct - convert to octal
* @argumentos: number to convert
* Return: len of octal number
*/

int print_oct(va_list argumentos)
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

	if (n == 1)
	{
		_putchar(49);
		return (1);
	}

	while (n >= 8)
	{
		mod = n % 8;
		n = n / 8;
		st[i] = mod;
		i++;
		if (n <= 8)
		{
			st[i] = n;
		}
	}

	for (j = i  ; j >= 0 ; j--)
	{
		_putchar(st[j] + '0');
	}
	return (i + 1);
}
