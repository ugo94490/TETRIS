/*
** EPITECH PROJECT, 2019
** assign_two.c
** File description:
** assign_two.c
*/

#include "tetris.h"

int set_drop(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0 || my_strcmp(optarg, "leftk") == 0)
        return (assign_drop("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0 || my_strcmp(optarg, "rightk")
        == 0)
        return (assign_drop("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0 || my_strcmp(optarg, "downk") == 0)
        return (assign_drop("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0 || my_strcmp(optarg, "topk") == 0)
        return (assign_drop("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_drop("(space)", arg));
    else {
        free(arg->key_drop);
        arg->key_drop = my_strdup(optarg);
        return (0);
    }
    return (84);
}

int assign_turn(char *str, arg_t *arg)
{
    free(arg->key_turn);
    arg->key_turn = my_strdup(str);
    return (0);
}

int set_turn(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0 || my_strcmp(optarg, "leftk") == 0)
        return (assign_turn("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0 || my_strcmp(optarg, "rightk")
        == 0)
        return (assign_turn("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0 || my_strcmp(optarg, "downk") == 0)
        return (assign_turn("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0 || my_strcmp(optarg, "topk") == 0)
        return (assign_turn("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_turn("(space)", arg));
    else {
        free(arg->key_turn);
        arg->key_turn = my_strdup(optarg);
        return (0);
    }
    return (84);
}

int assign_right(char *str, arg_t *arg)
{
    free(arg->key_right);
    arg->key_right = my_strdup(str);
    return (0);
}

int set_right(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0 || my_strcmp(optarg, "leftk") == 0)
        return (assign_right("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0 || my_strcmp(optarg, "rightk")
        == 0)
        return (assign_right("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0 || my_strcmp(optarg, "downk") == 0)
        return (assign_right("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0 || my_strcmp(optarg, "topk") == 0)
        return (assign_right("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_right("(space)", arg));
    else {
        free(arg->key_right);
        arg->key_right = my_strdup(optarg);
        return (0);
    }
    return (84);
}
