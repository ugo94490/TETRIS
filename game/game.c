/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game
*/

#include <time.h>
#include "tetris.h"
#include "game.h"

void game_loop(game_t *game)
{
    clock_t clock;

    refresh_tetris(game);
    while (game->lost == 0) {
        clock = get_actual_time(game->last_reinit);
        print_game(game);
        if (clock >= game->time_fall) {
            move_tetr_down(game, game->actual_tetrimino);
            reinit_clock(&(game->last_reinit));
        }
        analyse_event(game);
    }
}

void init_game(arg_t *arg)
{
    game_t game = create_game_struct(arg);
    WINDOW *window;

    srand(time(0));
    window = initscr();
    nodelay(window, true);
    noecho();
    raw();
    keypad(stdscr, TRUE);
    if (LINES >= arg->map_y + 10 && COLS >= arg->map_x + 2) {
        if (game.map != NULL && game.tetriminos != NULL)
            game_loop(&game);
    }
    destroy_game(&game);
    endwin();
    if (LINES < arg->map_y + 10 || COLS < arg->map_x + 2)
        write(2, "Please enlarge your terminal\n", 29);
}
