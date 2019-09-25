/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game
*/

#include <time.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "graphics.h"
#include "systems.h"
#include "sounds.h"
#include "tetris.h"
#include "game.h"

void analyse_event_pause(game_t *game, int *pause)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window->window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(game->window->window);
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyP))
            *pause = 0;
    }
}

void pausegame(game_t *game)
{
    int pause = 1;

    while (sfRenderWindow_isOpen(game->window->window) && pause == 1)
        analyse_event_pause(game, &pause);
}

void game_loop(game_t *game)
{
    clock_sf clock = create_clock();

    refresh_tetris(game);
    while (game->lost == 0 && sfRenderWindow_isOpen(game->window->window)) {
        clock.time = sfClock_getElapsedTime(clock.clock);
        print_game(game);
        if (clock.time.microseconds >= game->time_fall) {
            move_tetr_down(game, game->actual_tetrimino);
            sfClock_restart(clock.clock);
        }
        analyse_event(game);
    }
    destroy_clock(&clock);
}

void init_game(arg_t *arg)
{
    window_t window = create_window(800, 600, 32, "tetris");
    game_t game = create_game_struct(arg, &window);
    sfMusic *music = sfMusic_createFromFile("assets/theme.ogg");

    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    game.sprite = create_sprite("assets/blocks.png");
    sfRenderWindow_setFramerateLimit(window.window, 60);
    game_loop(&game);
    destroy_game(&game);
    sfMusic_destroy(music);
}
