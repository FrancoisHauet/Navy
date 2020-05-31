/*
** EPITECH PROJECT, 2019
** find_index.c
** File description:
** find_index.c
*/

int find_index(char c, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}