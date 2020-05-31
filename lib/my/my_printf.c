/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>

void my_switch_printf2(char *s, int l, va_list ap)
{
    switch (s[l]) {
        case 'S':
            my_printf_s(va_arg(ap, char*));
            break;
        case 'o':
            conv_base_oct(va_arg(ap, unsigned int));
            break;
        case 'x':
            conv_base_hexa(va_arg(ap, unsigned int));
            break;
        case 'X':
            conv_base_hexa_maj(va_arg(ap, unsigned int));
            break;
        case 'b':
            conv_base_bin(va_arg(ap, unsigned int));
            break;
        case 'u':
            my_put_nbr(va_arg(ap, unsigned int));
            break;
    }
}

void my_switch_printf(char *s, int l, va_list ap)
{
    switch (s[l]) {
        case 's':
            my_putstr(va_arg(ap, char*));
            break;
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case '%':
            my_putchar('%');
            break;
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 'C':
            my_putchar(va_arg(ap, int));
            break;
    }
}

void my_printf(char *s, ...)
{
    int l = 0;

    va_list ap;
    va_start(ap, s);
    while (s[l] != '\0') {
        if (s[l] == '%') {
            l++;
            my_switch_printf(s, l, ap);
            my_switch_printf2(s, l, ap);
        } else {
            my_putchar(s[l]);
        }
        l++;
    }
}