/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game
*/

#include <time.h>
#include "tetris.h"
#include "game.h"

void print_map(char **map, arg_t *arg)
{
    int i = 0;

    move(0, 0);
    printw("+");
    for (int j = 0; j < arg->map_x; j++)
        printw("-");
    printw("+");
    for (; map[i]; i++) {
        move(1+i, 0);
        printw("|%s|", map[i]);
    }
    move(i+1, 0);
    printw("+");
    for	(int j = 0; j < arg->map_x; j++)
        printw("-");
    printw("+");
}

void game(arg_t *arg, char **map)
{
    print_map(map, arg);
    getch();
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

void init_game(arg_t *arg)
{
    char **arr;
    link_t *tetriminos = NULL;

    tetriminos = create_linked(tetriminos);
    srand(time(0));
    initscr();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    arr = create_empty_tetris_arr(arg);
    if (arr != NULL)
        game(arg, arr);
    free_word_array(arr);
    endwin();
}
