/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** game.c
*/

#include "tetris.h"

int launch(arg_t *arg)
{
    int nb = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    printw("Hello World !!!");
    refresh();
    while (nb == 0)
        nb = getch();
    endwin();
    return (0);
}
