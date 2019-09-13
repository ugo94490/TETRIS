/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** analyse_events
*/

#include "tetris.h"
#include "game.h"

static void destroy_line(char **map, int index, game_t *game)
{
    char **cpy = copy_words(map, 0);

    for (int i = 0; map[0][i]; i++)
        map[0][i] = ' ';
    for (int y = 1; y <= index; y++)
        for (int x = 0; map[y][x]; x++)
            map[y][x] = cpy[y-1][x];
    free_word_array(cpy);
    game->lines += 1;
    game->score += 10;
    if (game->lines%10 == 0)
        game->level += 1;
}

static int sub_check_lines(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] != '*')
            return (0);
    return (1);
}

int check_lines(char **map, game_t *game)
{
    for (int y = 0; map[y]; y++)
        if (sub_check_lines(map[y]) == 1) {
            destroy_line(map, y, game);
            return (1);
        }
    return (0);
}

void refresh_tetris(game_t *game)
{
    game->time_fall = 1000000;
    for (int i = 1; i < game->level; i++)
        game->time_fall = game->time_fall - game->time_fall/10;
    while (check_lines(game->map, game) != 0);
    if (game->next_tetrimino == NULL)
        game->next_tetrimino = get_tetri_from_list(game);
    if (game->actual_tetrimino == NULL) {
        game->actual_tetrimino = game->next_tetrimino;
        game->next_tetrimino = NULL;
        if (check_can_go(game, game->actual_tetrimino->tetri,
        game->actual_tetrimino->x, game->actual_tetrimino->y) == 0)
            game->lost = 1;
    }
    if (game->next_tetrimino == NULL)
        game->next_tetrimino = get_tetri_from_list(game);
}

void analyse_event(game_t *game)
{
    int c = getch();

    refresh_tetris(game);
    if (c == game->keymap.quit)
        game->lost = -1;
    if (c == game->keymap.drop)
        while (game->actual_tetrimino)
            move_tetr_down(game, game->actual_tetrimino);
    refresh_tetris(game);
    if (c == game->keymap.left)
        move_tetr_left(game, game->actual_tetrimino);
    if (c == game->keymap.right)
        move_tetr_right(game, game->actual_tetrimino);
    if (c == game->keymap.turn)
        rotate_tetri(game, game->actual_tetrimino);
    if (c == game->keymap.pause)
        pausegame(game);
}
