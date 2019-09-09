/*
** EPITECH PROJECT, 2019
** misc;
** File description:
** misc.c
*/

#include "tetris.h"

int my_getnbr(char *st)
{
    int i = 0;
    int count = 0;
    long nbr = 0;

    for (; st[i] < '0' || st[i] > '9'; st[i] == '-' ? count++ : 0, i++);
    for (; st[i] >= '0' && st[i] <= '9'; nbr = (nbr * 10) + st[i] - '0', i++);
    count % 2 != 0 ? nbr *= -1 : 0;
    return ((nbr <= 2147483647 && nbr >= -2147483648) ? nbr : 0);
}

int set_struct(info_t *info)
{
    info->width = 0;
    info->height = 0;
    info->color = 0;
    info->tetri = NULL;
    info->ret = 0;
    return (0);
}

int reset_struct(info_t *info)
{
    info->width = 0;
    info->height = 0;
    info->color = 0;
    info->ret = 0;
    if (info->tetri != NULL)
        my_free_tab(info->tetri);
    return (0);
}

int display(info_t *info)
{
    if (info->ret == 84) {
        my_putstr("Error\n");
        return (0);
    }
    my_putstr("Size ");
    my_putnbr(info->width);
    my_putstr("*");
    my_putnbr(info->height);
    my_putstr(" :");
    my_putstr("  Color ");
    my_putnbr(info->color);
    my_putstr(" :\n");
    print_array(info->tetri);
    return (0);
}

int print_all_tetri(char **tab)
{
    char **trier = NULL;
    int ret = 0;

    if (nb_tetri(tab) == 84)
        return (84);
    trier = tetri_sort(tab);
    if (tetri(trier) == 84)
        ret = 84;
    my_free_tab(trier);
    return (ret);
}
