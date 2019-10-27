#include <stdio.h>
#include "holberton.h"

int main(void)
{
        int len;
        int len2;
        int a = -12.21;
        len = -3500.00;
        len2 = printf("Let's try to %% printf a simple sentence.\n");
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
        _printf("Len:[%d]\n", len);
        printf("Len:[%d]\n", len2);
        _printf("negative [%i]\n", a);
        return(0);
}
