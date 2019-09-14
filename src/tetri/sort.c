/*
** EPITECH PROJECT, 2019
** sort.c
** File description:
** sort.c
*/

#include "tetris.h"

int nb_tetri(char **tab)
{
    int nb = my_strlen_tab(tab);

    my_putstr("Tetriminos :  ");
    my_putnbr(nb);
    my_putstr("\n");
    if (nb == 0)
        return (84);
    return (0);
}

char **swap(char **files, int i)
{
    char *tmp;

    tmp = files[i];
    files[i] = files[i + 1];
    files[i + 1] = tmp;
    return (files);
}

char **tetri_sort(char **tab)
{
    char **tri = my_arraycpy(tab);
    int count = 1;

    while (count != 0) {
        count = 0;
        for (int i = 0; tri[i + 1] != NULL; i++)
            alp_srt(tri[i] + 11, tri[i + 1] + 11) == 1 ?
        tri = swap(tri, i), count++ : 0;
    }
    return (tri);
}

int count(char **tmp)
{
    int count = 0;

    for (int i = 0; tmp[i]; i++)
        for (int j = 0; tmp[i][j]; j++)
            tmp[i][j] == '*' ? count++ : 0;
    return (count);
}

int vrf_w(info_t *info, char **shape)
{
    char **tmp = NULL;
    int nb = 0;
    int save = 0;

    for (int i = 0; shape[i]; i++) {
        tmp = word_tab(shape[i], " ");
        if (check_line(tmp) == 84) {
            info->ret = 84;
            my_free_tab(tmp);
            return (84);
        }
        (nb = count(tmp)) > save ? save = nb : 0;
        my_free_tab(tmp);
    }
    if (save != info->width)
        return (info->ret = 84);
    return (0);
}
