/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** sub_draw_game
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "tetris.h"
#include "game.h"

void draw_tetri(game_t *game, int color, sfVector2f pos)
{
    sfSprite_setTextureRect(game->sprite.sprite, blockRects[color]);
    sfSprite_setPosition(game->sprite.sprite, pos);
    sfRenderWindow_drawSprite(game->window->window,
    game->sprite.sprite, NULL);
}

void sub_print_map(game_t *game, char **map, int i)
{
    for (int j = 0; map[i][j]; j++)
        if (map[i][j] == '*')
            draw_tetri(game, 6, create_vector2f(24*(j+1), 24*(i+1)));
}

void print_map(game_t *game, char **map, arg_t *arg)
{
    for (int j = 0; j < arg->map_x+2; j++) {
        draw_tetri(game, 7, create_vector2f(24*j, 0));
        draw_tetri(game, 7, create_vector2f(24*j, (arg->map_y+1)*24));
    }
    for (int j = 0; j < arg->map_y+2; j++) {
        draw_tetri(game, 7, create_vector2f(0, 24*j));
        draw_tetri(game, 7, create_vector2f(24*(arg->map_x+1), 24*j));
    }
    for (int i = 0; map && map[i]; i++)
        sub_print_map(game, map, i);
}
