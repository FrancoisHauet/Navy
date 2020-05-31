/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "game.h"

int while_s(ship_t **my_ships, int i)
{
    int a = 0;
    int j = 0;

    while (j < my_ships[i]->length) {
        if (my_ships[i]->boxes[j] != 0) {
            a = 1;
            return (a);
        }
        j++;
    }
    return (a);
}

static int my_ship(ship_t **my_ships)
{
    int a = 0;
    int i = 0;

    while (i < SHIPS_NBR) {
        a = while_s(my_ships, i);
        if (a == 1)
            return (1);
        i++;
    }
    return (0);
}

static int first_player(game_t *game)
{
    coords_t coords;
    char *input = NULL;
    int hit_value = 0;

    my_printf("attack: ");
    input = get_next_line(0);
    while (str_to_coords(input, &coords) != 0) {
        if (!input)
            return (2);
        free(input);
        input = get_next_line(0);
        my_printf("wrong position\n");
        my_printf("attack: ");
    }
    hit_value = player_turn(coords, game->enemy_pid);
    my_printf("%s: %s\n\n", input, hit_value == MISSED ||
    game->enemy_map[coords.y][coords.x] == HIT_CHAR ? "missed" : "hit");
    free(input);
    game->enemy_map[coords.y][coords.x] =
    (hit_value == MISSED ? MISS_CHAR : HIT_CHAR);
    return (hit_value == ALL_SUNK ? 0 : -1);
}

static int second_player(game_t *game)
{
    coords_t pos;
    int is_hit;
    int hit_value = MISSED;

    my_putstr("waiting for enemy's attack...\n");
    pos = wait_for_turn(game->enemy_pid);
    is_hit = hit_boat(game, pos);
    if (is_hit) {
        if (my_ship(game->my_ships))
            hit_value = HIT;
        else
            hit_value = ALL_SUNK;
    } else
        game->my_map[pos.y][pos.x] = MISS_CHAR;
    attack_another_player(game->enemy_pid, hit_value);
    my_printf("%c%c: %s\n\n", X_CHARS[pos.x], Y_CHARS[pos.y],
        (!is_hit || game->my_map[pos.y][pos.x] == HIT_CHAR ?
        "missed" : "hit"));
    return (hit_value == ALL_SUNK ? 1 : -1);
}

int loop_navy(game_t *game)
{
    int return_code = -1;
    int turn = (game->player == 1 ? 1 : 2);
    int i = 0;

    while (return_code == -1) {
        if (game->player == 1 && turn == 1)
            display_game(game);
        else if (game->player == 2 && turn == 2)
            display_game(game);
        i = 1;
        if (turn == 1)
            return_code = first_player(game);
        else if (turn == 2)
            return_code = second_player(game);
        turn = (turn == 1 ? 2 : 1);
    }
    if (return_code != 2) {
        display_game(game);
        my_putstr(return_code == 0 ? "I won\n" : "Enemy won\n");
    }
    return (return_code);
}