/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game.h
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>

#define MISSED 0
#define HIT 1
#define ALL_SUNK 2
#define VERTICAL 1
#define HORIZONTAL 2
#define X_CHARS "ABCDEFGH"
#define Y_CHARS "12345678"
#define MAP_SIZE 8
#define MAP_CHAR '.'
#define HIT_CHAR 'x'
#define MISS_CHAR 'o'
#define SHIPS_NBR 4
#define READ_SIZE 50

extern int global;

typedef struct coords_s {
    int x;
    int y;
} coords_t;

typedef struct ship_s {
    coords_t start;
    coords_t end;
    int length;
    int afloat;
    int direction;
    int *boxes;
} ship_t;

typedef struct s_game {
    pid_t enemy_pid;
    char **my_map;
    char **enemy_map;
    ship_t **my_ships;
    int player;
} game_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str, int size);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
void conv_base_hexa(unsigned int nb);
void conv_base_oct(unsigned int nb);
void conv_base_hexa_maj(unsigned int nb);
void conv_base_bin(unsigned int nb);
void simple_handler(int signum);
void my_printf(char *s, ...);
coords_t wait_for_turn(int pid);
void send_signal(int signum, int pid);
int update_map(game_t *game);
void map_display(char **map);
void display_game(game_t *game);
void display_h(void);
void attack_another_player(int pid, int value);
static int my_ship(ship_t **my_ships);
static int first_player(game_t *game);
static int second_player(game_t *game);
int loop_navy(game_t *game);
static int set_char_map(game_t *game, ship_t *ship);
int player_turn(coords_t pos, int enemy_pid);
int analyse_signals(int pid);
char **split_string(char *str, char delim, char delim2);
int str_to_coords(char *str, coords_t *coords);
int free_words(char **words);
char *get_next_line(const int fd);
int get_ships(int ac, char **av, game_t *game);
int hit_boat(game_t *game, coords_t coords);
int set_up(int ac, char **av, game_t *game);
void my_printf_s(char *str);
int init_first_player(game_t *game);
int init_second_player(game_t *game, char *str);
int destroy_navy(game_t *game);
int find_index(char c, char *str);
int overlap_ships(char c, ship_t **my_ships, ship_t *ship);