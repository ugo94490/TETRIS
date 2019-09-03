/*
** EPITECH PROJECT, 2019
** help.c
** File description:
** help.c
*/

#include "tetris.h"

int disp_first(char *str)
{
    my_putstr("Usage :  ");
    my_putstr(str);
    my_putstr(" [options]\nOptions:\n");
    return (0);
}

int help(char *str)
{
    disp_first(str);
    my_putstr(" --help                  Display this help\n"
    " -L --level={num}        Start Tetirs at level num (def: 1)\n"
    " -l --key-left={K}    Move the tetrimino LEFT using the K key"
    " (def: left arrow)\n -r --key-right={K}   Move the tetrimino RIGHT "
    "using the K key (def: right arrow)\n");
    my_putstr(" -t --key-turn={K}    TURN the tetrimino clockwise 90d using"
    " the K key (def: top arrow)\n");
    my_putstr(" -d --key-drop={K}    DROP the tetrimino using the K key (def:"
    " down arrow)\n");
    my_putstr(" -q --key-quit={K}    QUIT the game using the K key (def: ‘q’"
    " key)\n");
    my_putstr(" -p --key-pause={K}   PAUSE/RESTART the game using the K key "
    "(def: space bar)\n");
    my_putstr(" --map-size={row,col} Set the numbers of rows and columns of "
    "the map (def: 20,10)\n");
    my_putstr(" -w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr(" -D --debug           Debug mode (def: false)\n");
    return (0);
}
