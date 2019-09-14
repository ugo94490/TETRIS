/*
** EPITECH PROJECT, 2019
** struct_disp.c
** File description:
** struct_disp.c
*/

#include "tetris.h"

int tetri(char **tab)
{
    int ret = 0;
    info_t *info = malloc(sizeof(info_t));

    for (int i = 0; tab[i]; i++) {
        set_struct(info);
        my_putstr("Tetriminos :  Name ");
        display_name(my_strdup(tab[i]));
        my_putstr(" :  ");
        if (get_file(info, tab[i]) == 84)
            info->ret = 84;
        display(info);
        if (info->ret == 84)
            ret = 84;
        reset_struct(info);
    }
    free(info);
    return (ret);
}

arg_t *init_arg(void)
{
    arg_t *arg = malloc(sizeof(arg_t));

    arg->level = 1;
    arg->key_left = my_strdup("left arrow");
    arg->key_right = my_strdup("right arrow");
    arg->key_turn = my_strdup("top arrow");
    arg->key_drop = my_strdup("down arrow");
    arg->key_quit = my_strdup("q");
    arg->key_pause = my_strdup("(space)");
    arg->map_x = 10;
    arg->map_y = 20;
    arg->hide = my_strdup("Yes");
    arg->debug = my_strdup("false");
    return (arg);
}

int free_struct(arg_t *arg)
{
    arg->key_left != NULL ? free(arg->key_left) : 0;
    arg->key_right != NULL ? free(arg->key_right) : 0;
    arg->key_turn != NULL ? free(arg->key_turn) : 0;
    arg->key_drop != NULL ? free(arg->key_drop) : 0;
    arg->key_quit != NULL ? free(arg->key_quit) : 0;
    arg->key_pause != NULL ? free(arg->key_pause) : 0;
    arg->hide != NULL ? free(arg->hide) : 0;
    arg->debug != NULL ? free(arg->debug) : 0;
    free(arg);
    return (0);
}

int disp_arrow(char *pri, char *str)
{
    int count = 0;

    my_putstr(pri);
    if (my_strcmp(str, "left arrow") == 0)
        my_putstr("^EOD") == 0 ? count++ : 0;
    if (my_strcmp(str, "right arrow") == 0)
        my_putstr("^EOC") == 0 ? count++ : 0;
    if (my_strcmp(str, "down arrow") == 0)
        my_putstr("^EOB") == 0 ? count++ : 0;
    if (my_strcmp(str, "top arrow") == 0)
        my_putstr("^EOA") == 0 ? count++ : 0;
    if (count == 0)
        my_putstr(str);
    my_putstr("\n");
    return (0);
}

int disp_level_size(int level, int x, int y)
{
    my_putstr("Level :  ");
    my_putnbr(level);
    my_putstr("\n");
    my_putstr("Size :  ");
    my_putnbr(y);
    my_putstr("*");
    my_putnbr(x);
    my_putstr("\n");
    return (0);
}
