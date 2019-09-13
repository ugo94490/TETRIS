/*
** EPITECH PROJECT, 2019
** convert.c
** File description:
** convert.c
*/

#include "tetris.h"

int convert_key(char *str)
{
    if (my_strcmp(str, "left arrow") == 0)
        return (KEY_LEFT);
    if (my_strcmp(str, "right arrow") == 0)
        return (KEY_RIGHT);
    if (my_strcmp(str, "down arrow") == 0)
        return (KEY_DOWN);
    if (my_strcmp(str, "top arrow") == 0)
        return (KEY_UP);
    if (my_strcmp(str, "(space)") == 0)
        return (KEY_BACKSPACE);
    return (str[0]);
}

keymap_t convert(arg_t *arg)
{
    keymap_t keymap;

    keymap.left = convert_key(arg->key_left);
    keymap.right = convert_key(arg->key_right);
    keymap.turn = convert_key(arg->key_turn);
    keymap.drop = convert_key(arg->key_drop);
    keymap.quit = convert_key(arg->key_quit);
    keymap.pause = convert_key(arg->key_pause);
    return (keymap);
}
