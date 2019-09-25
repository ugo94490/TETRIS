/*
** EPITECH PROJECT, 2019
** assign.c
** File description:
** assign.c
*/

#include "tetris.h"

int assign_pause(char *str, arg_t *arg)
{
    free(arg->key_pause);
    arg->key_pause = my_strdup(str);
    return (0);
}

int set_pause(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0 || my_strcmp(optarg, "leftk") == 0)
        return (assign_pause("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0 || my_strcmp(optarg, "rightk")
        == 0)
        return (assign_pause("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0 || my_strcmp(optarg, "downk") == 0)
        return (assign_pause("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0 || my_strcmp(optarg, "topk") == 0)
        return (assign_pause("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_pause("(space)", arg));
    else {
        free(arg->key_pause);
        arg->key_pause = my_strdup(optarg);
        return (0);
    }
    return (84);
}

int assign_quit(char *str, arg_t *arg)
{
    free(arg->key_quit);
    arg->key_quit = my_strdup(str);
    return (0);
}

int set_quit(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0 || my_strcmp(optarg, "leftk") == 0)
        return (assign_quit("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0 || my_strcmp(optarg, "rightk")
        == 0)
        return (assign_quit("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0 || my_strcmp(optarg, "downk") == 0)
        return (assign_quit("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0 || my_strcmp(optarg, "topk") == 0)
        return (assign_quit("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_quit("(space)", arg));
    else {
        free(arg->key_quit);
        arg->key_quit = my_strdup(optarg);
        return (0);
    }
    return (84);
}

int assign_drop(char *str, arg_t *arg)
{
    free(arg->key_drop);
    arg->key_drop = my_strdup(str);
    return (0);
}
