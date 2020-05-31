/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "game.h"

int main(int ac, char **av)
{
    int error_code = 84;
    game_t *game = malloc(sizeof(game_t));

    if (!game || set_up(ac, av, game) != 0)
        return (error_code);
    if (game->player == 1) {
        if (init_first_player(game) != 0)
            return (error_code);
    } else if (game->player == 2) {
        if (init_second_player(game, av[1]) != 0)
            return (error_code);
    } else
        return (error_code);
    error_code = loop_navy(game);
    destroy_navy(game);
    return (error_code);
}