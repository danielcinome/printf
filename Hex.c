#include "holberton.h"
#include <stdarg.h>

/**
* print_Hex - convert to hex
* @argumentos: number to convert
* Return: len of hex number
*/

int print_Hex(va_list argumentos)
{
	int st[1000000];
	int mod, j, i = 0;
	unsigned int n;

	n = va_arg(argumentos, unsigned int);
	if (n == 0)
	{	_putchar(48);
		return (1);
	}

	while (n > 0)
	{
		mod = n % 16;
		n = n / 16;
		if (mod < 10)
			st[i] = mod + 48;
		if (mod != 0 && mod > 10)
			st[i] = mod + 55;
		i++;
	}

	for (j = i - 1 ; j >= 0 ; j--)
	{
		_putchar(st[j]);
	}
	return (i);
}
