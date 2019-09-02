/*
** EPITECH PROJECT, 2019
** check.c
** File description:
** check.c
*/

#include "tetris.h"

int check_name(char *str)
{
    str = my_revstr(str);
    if (my_strncmp("onimirtet.", str, 10) != 0)
        return (84);
    return (0);
}

int check_nbr(char *c)
{
    for (int i = 0; c[i]; i++)
        if ((c[i] > '9' || c[i] < '0'))
            return (84);
    return (0);
}

int vrf_c(info_t *info)
{
    if (info->color > 8 || info->color < 0)
        return (info->ret = 84);
    return (0);
}

int check_line(char **str)
{
    int ret = 0;

    if (str == NULL)
        return (84);
    for (int j = 0; j < my_strlen_tab(str); j++)
        for (int i = 0; str[j][i]; i++)
            str[j][i] != '*' ? ret = 84 : 0;
    return (ret);
}

int vrf_h(info_t *info, char **shape)
{
    char **tmp = NULL;

    for (int i = 0; shape[i]; i++) {
        tmp = word_tab(shape[i], " ");
        if (check_line(tmp) == 84 || count(tmp) < 1) {
            info->ret = 84;
            my_free_tab(tmp);
            return (84);
        }
        my_free_tab(tmp);
    }
    if (my_strlen_tab(shape) != info->height)
        return (info->ret = 84);
    return (0);
}
