/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** second_player_turn.c
*/

#include "game.h"

void display_h(void)
{
    my_printf("USAGE\n");
    my_printf("        ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player."\
        " pid of the first player.\n\tnavy_positions:"\
        " file representing the positions of the ships.\n");
}

void attack_another_player(int pid, int value)
{
    send_signal(((value == MISSED) ? SIGUSR2 : SIGUSR1), pid);
    send_signal(((value == ALL_SUNK) ? SIGUSR2 : SIGUSR1), pid);
}

coords_t wait_for_turn(int pid)
{
    coords_t pos = {0, 0};

    signal(SIGUSR1, &simple_handler);
    signal(SIGUSR2, &simple_handler);
    while (1) {
        pause();
        if (global == -1 && pos.y > 0)
            break;
        else if (global == -1)
            pos.x++;
        else
            pos.y++;
        kill(pid, SIGUSR1);
    }
    pos.y--;
    pos.x--;
    return (pos);
}
