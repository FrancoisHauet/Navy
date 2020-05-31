/*
** EPITECH PROJECT, 2019
** my_printf_s
** File description:
** my_printf_s
*/

#include "my.h"

void print_zero(int res)
{
    if (res > 0 && res < 8) {
        my_putchar('0');
        my_putchar('0');
    } else if (res > 7 && res < 50)
        my_putchar('0');
}

void my_printf_s(char *str)
{
    int i = 0;
    int res;

    while (str[i] != 0) {
        res = (int) str[i];
        if (res < 32 || res == 127) {
            my_putchar('\\');
            print_zero(res);
            conv_base_oct(res);
        } else
            my_putchar(res);
        i++;
    }
}