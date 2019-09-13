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

void sub_print_actual_tetri(game_t *game, info_t *tetri, int posx, int posy)
{
    move(posy + 1 + tetri->y, posx + 1 + tetri->x);
    if (tetri->tetri[posy][posx] == '*')
        printw("*");
}

void print_tetri(game_t *game, info_t *tetri)
{
    for (int y = 0; tetri->tetri[y]; y++)
        for (int x = 0; tetri->tetri[y][x]; x++)
            sub_print_actual_tetri(game, tetri, x, y);
}

void print_infos(game_t *game)
{
    move(game->arg->map_y+2, 0);
    printw("level: %d", game->level);
    move(game->arg->map_y+3, 0);
    printw("high score: %d", game->high_score);
    move(game->arg->map_y+4, 0);
    printw("score: %d", game->score);
    move(game->arg->map_y+5, 0);
    printw("lines: %d", game->lines);
}

void print_game(game_t *game)
{
    game->next_tetrimino->y = game->arg->map_y + 7;
    game->next_tetrimino->x = 0;
    print_map(game->map, game->arg);
    print_tetri(game, game->actual_tetrimino);
    print_infos(game);
    if (game->hide_next == 0) {
        move(game->arg->map_y + 7, 0);
        printw("next:");
        print_tetri(game, game->next_tetrimino);
    }
    game->next_tetrimino->y = 0;
}
