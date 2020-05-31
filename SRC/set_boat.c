/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** set_boat.c
*/

#include "game.h"

static int set_direction(ship_t *ship)
{
    coords_t buff_coord;

    if (ship->start.x > ship->end.x || ship->start.y > ship->end.y) {
        buff_coord = ship->start;
        ship->start = ship->end;
        ship->end = buff_coord;
    }
    if (ship->start.x - ship->end.x  == 0) {
        if (ship->start.y - ship->end.y == ship->length - 1)
            ship->direction = VERTICAL;
        if (ship->start.y - ship->end.y == (ship->length - 1) * -1)
            ship->direction = VERTICAL;
    }
    else if (ship->start.y - ship->end.y  == 0) {
        if (ship->start.x - ship->end.x == ship->length - 1)
            ship->direction = HORIZONTAL;
        if (ship->start.x - ship->end.x == (ship->length - 1) * - 1)
            ship->direction = HORIZONTAL;
    }
    return (ship->direction == 0 ? 84 : 0);
}

static char **split_coords(char *line)
{
    int size = 0;
    int i = 0;
    char **words = split_string(line, ':', ':');

    if (!words)
        return (NULL);
    while (words[size] != NULL)
        size++;
    if (size != 3)
        return (NULL);
    i = 4;
    if (my_strlen(words[0]) != 1)
        return (NULL);
    return (words);
}

static int set_ship(char *line, ship_t **my_ships, int i)
{
    char **words = split_coords(line);

    my_ships[i] = malloc(sizeof(ship_t));
    if (!my_ships[i] || !words)
        return (84);
    my_ships[i]->afloat = 1;
    my_ships[i]->length = my_getnbr(words[0]);
    if (my_ships[i]->length != i + 2 ||
    str_to_coords(words[1], &(my_ships[i]->start)) != 0 ||
    str_to_coords(words[2], &(my_ships[i]->end)) != 0)
        return (84);
    if (set_direction(my_ships[i]) != 0)
        return (84);
    my_ships[i]->boxes = malloc(sizeof(int) * my_ships[i]->length);
    if (!(my_ships[i]->boxes))
        return (84);
    for (int j = 0; j < my_ships[i]->length; j++)
        my_ships[i]->boxes[j] = 1;
    free_words(words);
    return (0);
}

int overlap_ships(char c, ship_t **my_ships, ship_t *ship)
{
    for (int i = 0; i < SHIPS_NBR;i++) {
        if (my_ships[i]->length == ship->length)
            continue;
        if (c == (char)(my_ships[i]->length + 48))
            return (1);
    }
    return (0);
}

int get_ships(int ac, char **av, game_t *game)
{
    int fd = -1;
    char *line = NULL;
    char *file_name = NULL;
    int i = 0;

    file_name = (ac == 2) ? av[1] : av[2];
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return (84);
    line = get_next_line(fd);
    while (line != NULL) {
        if (i >= SHIPS_NBR)
            return (84);
        if (set_ship(line, game->my_ships, i) != 0)
            return (84);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return (i == SHIPS_NBR ? 0 : 84);
}