/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** print_game
*/

#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "tetris.h"
#include "game.h"

void sub_print_actual_tetri(game_t *game, info_t *tetri, int posx, int posy)
{
    sfVector2f pos = {(posx+1+tetri->x) * 24, (1+posy+tetri->y) * 24};

    sfSprite_setTextureRect(game->sprite.sprite, blockRects[tetri->color]);
    sfSprite_setPosition(game->sprite.sprite, pos);
    if (tetri->tetri[posy][posx] == '*')
        sfRenderWindow_drawSprite(game->window->window,
        game->sprite.sprite, NULL);
}

void print_tetri(game_t *game, info_t *tetri)
{
    for (int y = 0; tetri->tetri[y]; y++)
        for (int x = 0; tetri->tetri[y][x]; x++)
            sub_print_actual_tetri(game, tetri, x, y);
}

void print_infos(game_t *game)
{
    game->timer = clock();
    move(game->arg->map_y+2, 0);
    printw("level: %d", game->level);
    move(game->arg->map_y+3, 0);
    printw("high score: %d", game->high_score);
    move(game->arg->map_y+4, 0);
    printw("score: %d", game->score);
    move(game->arg->map_y+5, 0);
    printw("lines: %d", game->lines);
    move(game->arg->map_y+6, 0);
    printw("time: %02d:%02d", (game->timer/CLOCKS_PER_SEC)/60,
    (game->timer/CLOCKS_PER_SEC)%60);
}

void print_game(game_t *game)
{
    sfRenderWindow_clear(game->window->window, sfBlack);
    game->next_tetrimino->y = game->arg->map_y + 7;
    game->next_tetrimino->x = 0;
    print_map(game, game->map, game->arg);
    print_tetri(game, game->actual_tetrimino);
    if (game->hide_next == 0) {
        game->next_tetrimino->y = 0;
        game->next_tetrimino->x = game->arg->map_x + 4;
        print_tetri(game, game->next_tetrimino);
        game->next_tetrimino->x = 0;
    }
    game->next_tetrimino->y = 0;
    sfRenderWindow_display(game->window->window);
}
