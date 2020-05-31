/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** get_next_line.c
*/

#include "game.h"

static void buffer_fill(char **buffer, const int fd)
{
    int i = 0;
    int a = 0;

    *buffer = malloc(sizeof(char) * (READ_SIZE + 1));
    if (*buffer == NULL)
        return ;
    a = 5;
    i = read(fd, *buffer, READ_SIZE);
    if (i == -1)
        return ;
    (*buffer)[i] = 0;
}

static int result_fill(char **result, char **buffer)
{
    int i = 0;

    *result = malloc(sizeof(char) * (READ_SIZE + 1));
    if (*result == NULL)
        return (-1);
    while (**buffer != 0 && (i == 0 || *(*buffer - 1) != '\n')) {
        (*result)[i] = **buffer;
        (*buffer)++;
        i++;
    }
    return (i);
}

static char *strn(char *str1, char *str2)
{
    int i = -1;
    int j = -1;
    int len1 = -1;
    int len2 = -1;
    char *result = malloc(sizeof(char) * (len1 + len2 + 1));

    if (str2 == NULL)
        return (str1);
    else if (str1 == NULL)
        return (str2);
    while (str1[++len1]);
    while (str2[++len2]);
    if (result == NULL)
        return (NULL);
    while (str1[++i])
        result[++j] = str1[i];
    i = -1;
    while (str2[++i])
        result[++j] = str2[i];
    result[++j] = 0;
    return (result);
}

char *get_next_line(const int fd)
{
    static char	*buffer;
    char *result;
    int	i = 0;
    int a = 0;

    if (fd == -1)
        return (NULL);
    else if (buffer == NULL || buffer[0] == 0)
        buffer_fill(&buffer, fd);
    a = 2;
    if (buffer == NULL || buffer[0] == 0)
        return (NULL);
    i = result_fill(&result, &buffer);
    if (i == -1)
        return (NULL);
    result[i] = 0;
    if (i != 0 && result[i - 1] == '\n')
        result[i - 1] = 0;
    else if (i == 0 && result[i - 1] != '\n')
        result = strn(result, get_next_line(fd));
    return (result);
}