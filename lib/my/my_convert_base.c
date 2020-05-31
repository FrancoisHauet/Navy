/*
** EPITECH PROJECT, 2019
** my_convert_base
** File description:
** my_convert_base
*/

#include "my.h"

void conv_base_hexa(unsigned int nb)
{
    int ret;

    if (nb >= 16) {
        ret = nb % 16;
        nb = nb / 16;
        conv_base_hexa(nb);
    } else if (nb > 0) {
        ret = nb % 16;
        nb = nb / 16;
    }
    if (ret > 9)
        my_putchar(ret + 87);
    else
        my_putchar(ret + 48);
}

void conv_base_oct(unsigned int nb)
{
    int ret;

    if (nb >= 8) {
        ret = nb % 8;
        nb = nb / 8;
        conv_base_oct(nb);
    } else if (nb > 0) {
        ret = nb % 8;
        nb = nb / 16;
    }
    my_putchar(ret + 48);
}

void conv_base_hexa_maj(unsigned int nb)
{
    int ret;

    if (nb >= 16) {
        ret = nb % 16;
        nb = nb / 16;
        conv_base_hexa_maj(nb);
    } else if (nb > 0) {
        ret = nb % 16;
        nb = nb / 16;
    }
    if (ret > 9)
        my_putchar(ret + 55);
    else
        my_putchar(ret + 48);
}

void conv_base_bin(unsigned int nb)
{
    int ret;

    if (nb >= 2) {
        ret = nb % 2;
        nb = nb / 2;
        conv_base_bin(nb);
    } else if (nb > 0) {
        ret = nb % 2;
        nb = nb / 2;
    }
    my_putchar(ret + 48);
}