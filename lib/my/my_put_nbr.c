/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "my.h"

int ne(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
        return (nb);
    }
    return (nb);
}

int my_put_nbr(int nb)
{
    long nbr = 1;

    nb = ne(nb);
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    while (nb % nbr != nb) {
        nbr *= 10;
    }
    for (nbr; nbr >= 10; nbr /= 10) {
        my_putchar((nb % nbr) / (nbr / 10) + 48);
    }
    return (0);
}
