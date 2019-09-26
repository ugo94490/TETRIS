/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** tools.c
*/

#include "tetris.h"

static char *itoa_zero(char *nbr)
{
    nbr[0] = '0';
    nbr[1] = '\0';
    return (nbr);
}

char *my_itoa(int nb, char *nbr)
{
    bool sign = false;
    int tmp = 0;
    int i = 0;

    if (nb == 0)
        return (itoa_zero(nbr));
    if (nb < 0) {
        sign = true;
        nb = -nb;
    }
    for (i = 0; nb != 0; i++) {
        tmp = nb % 10;
        nbr[i] = tmp + '0';
        nb = nb / 10;
    }
    if (sign == true)
        nbr[i] = '-';
    nbr[i] = '\0';
    my_revstr(nbr);
    return (nbr);
}

int my_int(int nb)
{
    int len = 0;
    int compteur = nb;

    while (compteur > 0) {
        compteur /= 10;
        len++;
    }
    len++;
    return (len);
}
