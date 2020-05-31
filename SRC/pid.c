/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** pid.c
*/

#include "game.h"

int global;

static void sig_handler(int signum, siginfo_t *info, void *context)
{
    if (signum != SIGUSR1 && signum != SIGUSR2)
        return;
    global = info->si_pid;
    if (context == NULL)
        return;
}

void simple_handler(int signum)
{
    if (signum == SIGUSR2)
        global = -2;
    else if (signum == SIGUSR1)
        global = -1;
}

int init_second_player(game_t *game, char *str)
{
    int enemy_pid = my_getnbr(str);

    if (enemy_pid <= 0)
        return (84);
    game->enemy_pid = enemy_pid;
    my_printf("my_pid: %i\n", getpid());
    kill(enemy_pid, SIGUSR1);
    signal(SIGUSR1, &simple_handler);
    pause();
    my_putstr("successfully connected\n\n");
    return (0);
}

int init_first_player(game_t *game)
{
    int pid = getpid();
    struct sigaction act;

    act.sa_sigaction = &sig_handler;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    my_printf("my_pid: %i\n", pid);
    my_putstr("waiting for enemy connection...\n\n");
    sigaction(SIGUSR1, &act, NULL);
    pause();
    game->enemy_pid = global;
    usleep(1000);
    kill(game->enemy_pid, SIGUSR1);
    my_putstr("enemy connected\n");
    return (0);
}
