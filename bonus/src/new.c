/*
** EPITECH PROJECT, 2019
** new.c
** File description:
** new.c
*/

#include "tetris.h"

int tetris(char **tetrimino_name, arg_t *arg)
{
    my_putstr("Press any key to start Tetris\n");
    wait_event(1);
    wait_event(0);
    init_game(arg);
    free_struct(arg);
    my_free_tab(tetrimino_name);
    return (0);
}
