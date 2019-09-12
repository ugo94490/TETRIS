/*
** EPITECH PROJECT, 2019
** disp.c
** File description:
** disp.c
*/

#include "tetris.h"

int display_arg(arg_t *arg)
{
    my_putstr("*** DEBUG MODE ***\n");
    disp_arrow("Key Left :  ", arg->key_left);
    disp_arrow("Key Right :  ", arg->key_right);
    disp_arrow("Key Turn :  ", arg->key_turn);
    disp_arrow("Key Drop :  ", arg->key_drop);
    disp_arrow("Key Quit :  ", arg->key_quit);
    disp_arrow("Key Pause :  ", arg->key_pause);
    disp_arrow("Next :  ", arg->hide);
    disp_level_size(arg->level, arg->map_y, arg->map_x);
    return (0);
}

int set_hide_o_debug(int nb, arg_t *arg)
{
    if (nb == 'w') {
        if (arg->hide != NULL)
            free(arg->hide);
        arg->hide = my_strdup("No");
    }
    if (nb == 'D') {
        if (arg->debug != NULL)
            free(arg->debug);
        arg->debug = my_strdup("true");
    }
    return (0);
}

int check_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] > '9' || str[i] < '0')
            return (84);
    return (0);
}

int check_size(arg_t *arg)
{
    char *buffer = my_strdup(optarg);
    char **tab = word_tab(buffer, ",");

    if (my_strlen_tab(tab) != 2) {
        my_free_tab(tab);
        free(buffer);
        return (84);
    }
    if (check_number(tab[0]) == 84 || check_number(tab[1]) == 84) {
        my_free_tab(tab);
        free(buffer);
        return (84);
    }
    arg->map_y = my_getnbr(tab[0]);
    arg->map_x = my_getnbr(tab[1]);
    my_free_tab(tab);
    free(buffer);
    return (0);
}

int set_map_size(arg_t *arg)
{
    if (check_size(arg) == 84)
        return (84);
    return (0);
}
