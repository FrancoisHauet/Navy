/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** task03
*/

char *my_revstr(char *str)
{
    int i = 0;
    int strlen = 0;
    int max = 0;
    int c = 0;

    for (strlen; str[strlen] != '\0'; strlen++);
    max = strlen / 2;
    for (i; i < strlen; i++) {
        c = str[i];
        str[i] = str[strlen - 1];
        str[strlen - 1] = c;
        strlen--;
    }
    return (str);
}    
