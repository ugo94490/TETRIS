/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** insert tetri
*/

#include "tetris.h"
#include "game.h"

void sub_insert_tetri(game_t *game, info_t *tetrimino, int posx, int posy)
{
    if (tetrimino->tetri[posy][posx] == '*' &&
    posx + tetrimino->x >= 0 && posx + tetrimino->x <
    game->arg->map_x && posy + tetrimino->y >= 0 &&
    posy +tetrimino->y <= game->arg->map_y)
        game->map[posy + tetrimino->y][posx + tetrimino->x] = '*';
}

void insert_tetri_in_map(game_t *game, info_t *tetrimino)
{
    for (int y = 0; tetrimino->tetri[y]; y++)
        for (int x = 0; tetrimino->tetri[y][x]; x++)
            sub_insert_tetri(game, tetrimino, x, y);
}
