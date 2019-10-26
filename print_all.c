#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
*printchar - print a character
*@lista: parameters to print
*/

void printchar(va_list lista)
{
        printf("%c", va_arg(lista, int));
}

/**
*printint - print an integer
*@lista: parameters to print
*/

void printint(va_list lista)
{
        printf("%d", va_arg(lista, int));
}

/**
*printfloat - print a float
*@lista: parameter to print
*/
void printfloat(va_list lista)
{
        printf("%f", va_arg(lista, double));
}

/**
*printstring - print a string
                                       
