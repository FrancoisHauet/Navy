/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** first_player_turn.c
*/

#include "game.h"

void send_signal(int signum, int pid)
{
    while (usleep(1000) != -1)
        kill(pid, signum);
}

int find_hit_missed(char *str)
{
    int val = -1;

    if (str[0] == '2')
        val = (MISSED);
    else if (str[1] == '1')
        val = (HIT);
    else
        val = (ALL_SUNK);
    free(str);
    return (val);
}

int analyse_signals(int pid)
{
    char *str = malloc(sizeof(char) * 3);
    int i = 0;

    if (!str)
        return (-1);
    while (str[i] = '0' && i < 2)
        i++;
    str[2] = '\0';
    i = 0;
    while (i < 2) {
        pause();
        if (global == -1)
            str[i] = '1';
        else
            str[i] = '2';
        kill(pid, SIGUSR1);
        i++;
    }
    return (find_hit_missed(str));
}

int player_turn(coords_t pos, int enemy_pid)
{
    int i = 0;

    signal(SIGUSR1, &simple_handler);
    signal(SIGUSR2, &simple_handler);
    while (i <= pos.x) {
        send_signal(SIGUSR1, enemy_pid);
        i++;
    }
    i = 0;
    while (i <= pos.y) {
        send_signal(SIGUSR2, enemy_pid);
        i++;
    }
    kill(enemy_pid, SIGUSR1);
    return (analyse_signals(enemy_pid));
}
