/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int time = *a;

    *a = *b;
    *b = time;
}
