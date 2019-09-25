/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** move_tetriminos
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "tetris.h"
#include "game.h"

static int sub_check_can_go(game_t *game, char c, int posx, int posy)
{
    if (c != '*')
        return (1);
    if (posx < 0 || posy < 0 || posx >= game->arg->map_x ||
    posy >= game->arg->map_y)
        return (0);
    else if (game->map[posy][posx] == '*')
        return (0);
    return (1);
}

int check_can_go(game_t *game, char **tetri, int posx, int posy)
{
    int can_go = 1;

    for (int y = 0; tetri[y] && can_go == 1; y++)
        for (int x = 0; tetri[y][x] && can_go == 1; x++)
            can_go = sub_check_can_go(game, tetri[y][x], posx + x, posy + y);
    return (can_go);
}

void move_tetr_down(game_t *game, info_t *tetrimino)
{
    if (check_can_go(game, tetrimino->tetri, tetrimino->x, tetrimino->y + 1))
        tetrimino->y += 1;
    else {
        clear();
        insert_tetri_in_map(game, tetrimino);
        free_word_array(tetrimino->tetri);
        free(tetrimino);
        game->actual_tetrimino = NULL;
    }
}

void move_tetr_left(game_t *game, info_t *tetrimino)
{
    if (check_can_go(game, tetrimino->tetri, tetrimino->x - 1, tetrimino->y))
        tetrimino->x -=1;
}

void move_tetr_right(game_t *game, info_t *tetrimino)
{
    if (check_can_go(game, tetrimino->tetri, tetrimino->x + 1, tetrimino->y))
        tetrimino->x +=1;
}
