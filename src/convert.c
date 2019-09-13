/*
** EPITECH PROJECT, 2019
** convert.c
** File description:
** convert.c
*/

#include "tetris.h"

int convert_key(char *str)
{
    if (my_strcmp(str, "left_arrow") == 0)
        return (KEY_LEFT);
    if (my_strcmp(str, "right_arrow") == 0)
        return (KEY_RIGHT);
    if (my_strcmp(str, "down_arrow") == 0)
        return (KEY_DOWN);
    if (my_strcmp(str, "top_arrow") == 0)
        return (KEY_UP);
    if (my_strcmp(str, "(space)") == 0)
        return (KEY_BACKSPACE);
    return (str[0]);
}

key_t *convert(arg_t *arg, key_t *key)
{
    key->left = convert_key(arg->key_left);
    key->right = convert_key(arg->key_right);
    key->turn = convert_key(arg->key_turn);
    key->drop = convert_key(arg->key_drop);
    key->quit = convert_key(arg->key_quit);
    key->pause = convert_key(arg->key_pause);
    return (key);
}
