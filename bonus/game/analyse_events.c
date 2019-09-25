/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** analyse_events
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "tetris.h"
#include "game.h"

void analyse_keyboard(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(game->window->window);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        move_tetr_down(game, game->actual_tetrimino);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        while (game->actual_tetrimino)
            move_tetr_down(game, game->actual_tetrimino);
    refresh_tetris(game);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        move_tetr_left(game, game->actual_tetrimino);
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        move_tetr_right(game, game->actual_tetrimino);
    if (sfKeyboard_isKeyPressed(sfKeyR))
        rotate_tetri(game, game->actual_tetrimino);
    if (sfKeyboard_isKeyPressed(sfKeyP))
        pausegame(game);
}

void analyse_event(game_t *game)
{
    sfEvent event;

    refresh_tetris(game);
    while (sfRenderWindow_pollEvent(game->window->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window->window);
        if (event.type == sfEvtKeyPressed)
            analyse_keyboard(game);
    }
}
