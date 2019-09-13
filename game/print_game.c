/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** print_game
*/

#include <time.h>
#include "tetris.h"
#include "game.h"

void print_map(char **map, arg_t *arg)
{
    int i = 0;

    move(0, 0);
    printw("+");
    for (int j = 0; j < arg->map_x; j++)
        printw("-");
    printw("+");
    for (; map && map[i]; i++) {
        move(1+i, 0);
        printw("|%s|", map[i]);
    }
    move(i+1, 0);
    printw("+");
    for (int j = 0; j < arg->map_x; j++)
        printw("-");
    printw("+");
}

void sub_print_actual_tetri(game_t *game, int posx, int posy)
{
    move(posy + 1 + game->actual_tetrimino->y,
    posx + 1 + game->actual_tetrimino->x);
    if (game->actual_tetrimino->tetri[posy][posx] == '*')
        printw("*");
}

void print_actual_tetri(game_t *game)
{
    for (int y = 0; game->actual_tetrimino->tetri[y]; y++)
        for (int x = 0; game->actual_tetrimino->tetri[y][x]; x++)
            sub_print_actual_tetri(game, x, y);
}

void print_game(game_t *game)
{
    print_map(game->map, game->arg);
    print_actual_tetri(game);
}
