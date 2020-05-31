/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** set_map.c
*/

#include "game.h"

static int set_map(char **my_map)
{
    int i = 0;
    int j = 0;

    while (i < MAP_SIZE) {
        my_map[i] = malloc(sizeof(char) * (MAP_SIZE + 1));
        if (!my_map[i])
            return (84);
        j = 0;
        while (j < MAP_SIZE) {
            my_map[i][j] = MAP_CHAR;
            j++;
        }
        my_map[i][MAP_SIZE] = '\0';
        i++;
    }
    return (0);
}

int set_up(int ac, char **av, game_t *game)
{
    if (ac < 2 || ac > 3)
        return (84);
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_h();
        return (0);
    }
    game->my_map = malloc(sizeof(char *) * MAP_SIZE);
    game->enemy_map = malloc(sizeof(char *) * MAP_SIZE);
    game->my_ships = malloc(sizeof(ship_t *) * SHIPS_NBR);
    game->player = (ac == 2 ? 1 : 2);
    game->enemy_pid = 0;
    if (!(game->enemy_map) || !(game->my_map) || !(game->my_ships))
        return (84);
    if (set_map(game->my_map) != 0 || set_map(game->enemy_map) != 0)
        return (84);
    if (get_ships(ac, av, game) != 0 || update_map(game) != 0)
        return (84);
    return (0);
}

int destroy_navy(game_t *game)
{
    int i = 0;
    int j = 0;

    while (i < SHIPS_NBR) {
        free(game->my_ships[i]->boxes);
        free(game->my_ships[i]);
        i++;
    }
    free(game->my_ships);
    while (j < MAP_SIZE) {
        free(game->my_map[j]);
        free(game->enemy_map[j]);
        j++;
    }
    free(game->my_map);
    free(game->enemy_map);
    free(game);
    return (0);
}