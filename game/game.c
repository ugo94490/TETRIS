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
    refresh_tetris(game);
    while (game->lost == 0) {
        print_game(game);
        analyse_event(game);
    }
}

char **create_empty_tetris_arr(arg_t *arg)
{
    char **arr = malloc(sizeof(char *) * arg->map_y+1);
    char *str = malloc(sizeof(char));

    if (arr == NULL || str == NULL)
        return (NULL);
    str[0] = '\0';
    for (int i = 0; i < arg->map_x; i++)
        str = my_strappend(str, ' ');
    for (int i = 0; i < arg->map_y+1; i++)
        arr[i] = my_strdup(str);
    arr[arg->map_y] = NULL;
    free(str);
    return (arr);
}

game_t create_game_struct(arg_t *arg)
{
    game_t game;

    game.tetriminos = NULL;
    game.tetriminos = create_linked(game.tetriminos);
    game.map = create_empty_tetris_arr(arg);
    game.actual_tetrimino = NULL;
    game.next_tetrimino = NULL;
    game.arg = arg;
    if (my_strcmp(arg->hide, "Yes") == 0)
        game.hide_next = 0;
    else
        game.hide_next = 1;
    game.level = arg->level;
    game.lines = 0;
    game.score = 0;
    game.high_score = 0;
    game.lost = 0;
    game.keymap = convert(arg);
    return (game);
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
    if (game.map != NULL && game.tetriminos != NULL)
        game_loop(&game);
    free_word_array(game.map);
    endwin();
}
