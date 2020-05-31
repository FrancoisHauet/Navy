/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** display_navy_map.c
*/

#include "game.h"

void map_display(char **map)
{
    my_printf(" |");
    for (int k = 0; k < MAP_SIZE * 2; k++)
        my_putchar((k % 2 == 0 ? X_CHARS[k/ 2] : ' '));
    my_printf("\n-+");
    for (int m = 0; m < MAP_SIZE * 2 - 1; m++)
        my_putchar('-');
    my_putchar('\n');
    for (int i = 0; i < MAP_SIZE; i++) {
        my_printf("%i|", i + 1);
        for (int j = 0; j < MAP_SIZE * 2; j++)
            my_putchar((j % 2 == 0) ? map[i][j / 2] : ' ');
        my_putchar('\n');
    }
}

void display_game(game_t *game)
{
    my_putstr("my positions:\n");
    update_map(game);
    map_display(game->my_map);
    my_putstr("\nenemy's positions:\n");
    map_display(game->enemy_map);
    my_putchar('\n');
}
