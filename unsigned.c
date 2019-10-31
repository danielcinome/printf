#include "holberton.h"

/**
* print_un - print unsigned number
* @i: number to print
* Return: lenght of number
*/

int print_un(va_list i)
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
