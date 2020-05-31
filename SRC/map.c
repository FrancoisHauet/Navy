/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** map.c
*/

#include "game.h"

int str_to_coords(char *str, coords_t *coords)
{
    if (!str || my_strlen(str) != 2)
        return (84);
    coords->x = find_index(str[0], X_CHARS);
    coords->y = find_index(str[1], Y_CHARS);
    if (coords->x == -1 || coords->y == -1)
        return (84);
    return (0);
}

static int update_boxes(ship_t *ship, coords_t coords)
{
    int i = 0;

    while (i < ship->length) {
        if (ship->direction == HORIZONTAL &&
            coords.x == ship->start.x + i) {
            ship->boxes[i] = 0;
            return (1);
        } else if (ship->direction == VERTICAL &&
            coords.y == ship->start.y + i) {
            ship->boxes[i] = 0;
            return (1);
        }
        i++;
    }
    return (0);
}

int hit_boat(game_t *game, coords_t coords)
{
    ship_t *ship = NULL;
    int i = 0;

    while (i < SHIPS_NBR) {
        ship = game->my_ships[i];
        if (coords.x >= ship->start.x && coords.x <= ship->end.x &&
            coords.y >= ship->start.y && coords.y <= ship->end.y) {
            return (update_boxes(ship, coords));
        }
        i++;
    }
    return (0);
}

static int set_char_map(game_t *game, ship_t *ship)
{
    for (int j = 0; j < ship->length; j++) {
        if (ship->direction == HORIZONTAL) {
            if (overlap_ships(
                game->my_map[ship->start.y][ship->start.x + j],
                game->my_ships, ship))
                return (84);
            game->my_map[ship->start.y][ship->start.x + j] =
            (ship->boxes[j] ? (char)(ship->length + 48) : HIT_CHAR);
        }
        else if (ship->direction == VERTICAL) {
            if (overlap_ships(
                game->my_map[ship->start.y + j][ship->start.x],
                game->my_ships, ship))
                return (84);
            game->my_map[ship->start.y + j][ship->start.x] =
            (ship->boxes[j] ? (char)(ship->length + 48) : HIT_CHAR);
        }
    }
    return (0);
}

int update_map(game_t *game)
{
    ship_t *ship = NULL;
    int i = 0;

    while (i < SHIPS_NBR) {
        ship = game->my_ships[i];
        if (set_char_map(game, ship) != 0)
            return (84);
        i++;
    }
    return (0);
}
