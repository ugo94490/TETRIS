/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game
*/

#include <time.h>
#include "tetris.h"
#include "game.h"

int get_list_len(link_t *list)
{
    int i = 0;

    for (; list != NULL; i++)
        list = list->next;
    return (i);
}

char **copy_words(char **words, int arg)
{
    int i = 0;
    int j = 0;
    char **copy;

    for (; words[i] != NULL; i++);
    copy = malloc(sizeof(char*) * (i+1+arg));
    if (copy == NULL)
        exit(84);
    copy[i] = NULL;
    for (i = 0; words[i] != NULL; i++) {
        copy[i] = malloc(sizeof(char)* (my_strlen(words[i])+1));
        if (copy[i] == NULL)
            exit(84);
    }
    for (i = 0; words[i] != NULL; i++) {
        for (j = 0; words[i][j] != '\0'; j++)
            copy[i][j] = words[i][j];
        copy[i][j] = '\0';
    }
    return (copy);
}

info_t *copy_tetrimino(info_t *to_copy)
{
    info_t *cpy = malloc(sizeof(info_t));

    cpy->width = to_copy->width;
    cpy->height = to_copy->height;
    cpy->color = to_copy->color;
    cpy->ret = to_copy->ret;
    cpy->x = 0;
    cpy->y = 0;
    cpy->tetri = copy_words(to_copy->tetri, 0);
    return (cpy);
}

info_t *get_tetri_from_list(game_t *game)
{
    link_t *cpy = game->tetriminos;
    int len = get_list_len(game->tetriminos);
    int randomnb = rand()%len;

    for (int i = 0; i < randomnb; i++)
        cpy = cpy->next;
    return (copy_tetrimino(cpy->info));
}

void refresh_tetris(game_t *game)
{
    if (game->next_tetrimino == NULL)
        game->next_tetrimino = get_tetri_from_list(game);
    if (game->actual_tetrimino == NULL) {
        game->actual_tetrimino = game->next_tetrimino;
        game->next_tetrimino = NULL;
    }
    if (game->next_tetrimino == NULL)
        game->next_tetrimino = get_tetri_from_list(game);
}

void analyse_event(game_t *game, int *loop)
{
    int c = getch();

    refresh_tetris(game);
    if (c == 113)
        *loop = 0;
    if (c == 258)
        move_tetr_down(game, game->actual_tetrimino);
    if (c == 260)
        move_tetr_left(game, game->actual_tetrimino);
    if (c == 261)
        move_tetr_right(game, game->actual_tetrimino);
    refresh_tetris(game);
}

void game_loop(game_t *game)
{
    int loop = 1;

    refresh_tetris(game);
    while (loop == 1) {
        print_game(game);
        analyse_event(game, &loop);
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
