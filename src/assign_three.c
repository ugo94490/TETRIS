/*
** EPITECH PROJECT, 2019
** assign_three.c
** File description:
** assign_three.c
*/

#include "tetris.h"

int assign_left(char *str, arg_t *arg)
{
    free(arg->key_left);
    arg->key_left = my_strdup(str);
    return (0);
}

int set_left(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0 || my_strcmp(optarg, "leftk") == 0)
        return (assign_left("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0 || my_strcmp(optarg, "rightk")
        == 0)
        return (assign_left("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0 || my_strcmp(optarg, "downk") == 0)
        return (assign_left("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0 || my_strcmp(optarg, "topk") == 0)
        return (assign_left("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_left("(space)", arg));
    else {
        free(arg->key_left);
        arg->key_left = my_strdup(optarg);
        return (0);
    }
    return (84);
}

int set_level(arg_t *arg)
{
    if (check_number(optarg) == 84)
        return (84);
    arg->level = my_getnbr(optarg);
    return (0);
}

int fill_arg(int flag, arg_t *arg)
{
    if (flag == 'w' || flag == 'D')
        return (set_hide_o_debug(flag, arg));
    if (flag == 'm')
        return (set_map_size(arg));
    if (flag == 'p')
        return (set_pause(arg));
    if (flag == 'q')
        return (set_quit(arg));
    if (flag == 'd')
        return (set_drop(arg));
    if (flag == 't')
        return (set_turn(arg));
    if (flag == 'r')
        return (set_right(arg));
    if (flag == 'l')
        return (set_left(arg));
    if (flag == 'L')
        return (set_level(arg));
    return (0);
}

int catch_arg(int ac, char **av, arg_t *arg)
{
    int nb = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", LONG_OPT, NULL);

    while (nb != -1) {
        if (nb == '?' || fill_arg(nb, arg) == 84)
            return (84);
        nb = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", LONG_OPT, NULL);
    }
    return (0);
}
