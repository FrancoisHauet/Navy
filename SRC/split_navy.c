/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** split_navy.c
*/

#include "game.h"

static int count_words(char *cpy, char delim, char delim2)
{
    int j = 0;
    int word_count = 0;

    for (; cpy[0] == delim || cpy[0] == delim2; cpy += 1);
    while (cpy[0] != '\0') {
        for (; cpy[0] == delim || cpy[0] == delim2; cpy += 1);
        for (j = 0; cpy[j] != delim && cpy[j] != delim2 &&
            cpy[j] != '\0'; j++);
        	cpy += j;
        word_count++;
        for (; cpy[0] == delim || cpy[0] == delim2; cpy += 1);
    }
    return (word_count);
}

static char **fill_words(char *cpy, char delim, char delim2, char **words)
{
    int j = 0;
    int word_count = 0;

    for (; cpy[0] == delim || cpy[0] == delim2; cpy += 1);
    while (cpy[0] != '\0') {
        for (; cpy[0] == delim || cpy[0] == delim2; cpy += 1);
        for (j = 0; cpy[j] != delim && cpy[j] != delim2
            && cpy[j] != '\0'; j++)
        words[word_count] = malloc(sizeof(char) * (j + 1));
        for (int i = 0; i < j; i++)
            words[word_count][i] = cpy[i];
        words[word_count][j] = '\0';
        cpy += j;
        for (; cpy[0] == delim || cpy[0] == delim2; cpy += 1);
        word_count++;
    }
    return (words);
}

char **split_string(char *str, char delim, char delim2)
{
    int word_count = 0;
    char **words;

    if (str == NULL || str[0] == '\0')
        return (NULL);
    word_count = count_words(str, delim, delim2);
    if (word_count == 0)
        return (NULL);
    words = malloc(sizeof(char *) * (word_count + 1));
    words[word_count] = NULL;
    return (fill_words(str, delim, delim2, words));
}

int free_words(char **words)
{
    int i = 0;

    if (!words)
        return (0);
    while (words[i] != NULL) {
        free(words[i]);
        i++;
    }
    free(words);
    return (0);
}
