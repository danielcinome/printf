#include <stdio.h>
#include "holberton.h"

int main(void)
{
        int len;
        int len2;
	int len3;
	int len4;
        int a = -12.21;
	char b = 'A';
	char *c = "paula";
        len = -3500.00;
/*	_printf("\%"); */
/*	printf("\%"); */
	len = _printf("1a%s\n", c);
	len2 = printf("1a%s\n", c);
	printf("%d\n", len);
	printf("%d\n", len2);
	_printf("1%c\n", b);
	printf("1%c\n", b);
	_printf("\\ , ' \"\n");
	printf("\\ , ' \"\n");
        len2 = _printf("Let's try to %% printf a simple sentence.\n");
        _printf("Character:[%c]\n", 'H');
        printf("Character:[%c]\n", 'H');
        _printf("String:[%s]\n", "I am a string !");
        printf("String:[%s]\n", "I am a string !");
        _printf("Length:[%i]\n", len);
        printf("Length:[%i]\n", len2);
        _printf("Negative:[%d]\n", -762534);
        printf("Negative:[%d]\n", -762534);
        len = _printf("Percent:[%%]\n");
        len2 = printf("Percent:[%%]\n");
	_printf("prueba %d\n", len);
	printf("pruba %d\n", len2);
	_printf("Len:[%d]\n", len);
        printf("Len:[%d]\n", len2);
        _printf("negative [%i]\n", a);
        _printf("%b\n", 98);
        _printf("%b\n", 1500);
	len3 = _printf("paula tiene un marcapaso %c\n", '3');
        len4 = printf("paula tiene un marcapaso %c\n", '3');
	_printf("%d\n", len3);
	printf("%i\n", len3);
	printf("%i\n", len4);
        return(0);
}

