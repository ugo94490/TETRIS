/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** init_destroy_game
*/

#include <time.h>
#include "tetris.h"
#include "game.h"

char **create_empty_tetris_arr(arg_t *arg)
{
    char **arr = malloc(sizeof(char *) * (arg->map_y+1));
    char *str = malloc(sizeof(char));
    int j = 0;

    if (arr == NULL || str == NULL)
        return (NULL);
    str[0] = '\0';
    for (int i = 0; i < arg->map_x; i++)
        str = my_strappend(str, ' ');
    for (; j < arg->map_y; j++)
        arr[j] = my_strdup(str);
    arr[j] = NULL;
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
    game.last_reinit = clock();
    return (game);
}

void destroy_tetrimino(info_t *tetrimino)
{
    if (tetrimino == NULL)
        return;
    free_word_array(tetrimino->tetri);
    free(tetrimino);
}

void destroy_tetrimino_list(link_t *list)
{
    if (list != NULL && list->next != NULL)
        destroy_tetrimino_list(list->next);
    if (list != NULL) {
        destroy_tetrimino(list->info);
        free(list);
    }
}

void destroy_game(game_t *game)
{
    destroy_tetrimino(game->actual_tetrimino);
    destroy_tetrimino(game->next_tetrimino);
    free_word_array(game->map);
    destroy_tetrimino_list(game->tetriminos);
}
