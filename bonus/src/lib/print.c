/*
** EPITECH PROJECT, 2019
** print.c
** File description:
** print.c
*/

#include "tetris.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}

int my_putnbr(int nb)
{
    int n = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    } else if (nb > 9) {
        my_putnbr(nb / 10);
        n = nb % 10;
        my_putchar(n + '0');
    }
    return (0);
}
