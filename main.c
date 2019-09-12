/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "tetris.h"

int check_over_arg(int ac, char **av)
{
    if (ac < 2)
        return (0);
    for (int i = 2; av[i]; i++) {
        if (av[i][0] != '-' && (av[i - 1][0] != '-' ||
            (av[i - 1][0] == '-' && av[i - 1][1] == '-')))
            return (84);
        if (av[i][0] != '-' && (my_strcmp(av[i - 1], "-w") == 0 ||
            my_strcmp(av[i - 1], "-D") == 0))
            return (84);
    }
    return (0);
}

char **init_tab(arg_t *arg)
{
    char **tab = NULL;

    tab = tab_realloc(tab, my_strdup(arg->key_left));
    tab = tab_realloc(tab, my_strdup(arg->key_right));
    tab = tab_realloc(tab, my_strdup(arg->key_turn));
    tab = tab_realloc(tab, my_strdup(arg->key_drop));
    tab = tab_realloc(tab, my_strdup(arg->key_quit));
    tab = tab_realloc(tab, my_strdup(arg->key_pause));
    return (tab);
}

int check_double_key(arg_t *arg)
{
    char **tab = init_tab(arg);
    int count = 0;

    for (int i = 0; tab[i]; i++) {
        count = 0;
        for (int j = 0; tab[j]; j++)
            my_strcmp(tab[i], tab[j]) == 0 ? count++ : 0;
        if (count != 1) {
            my_free_tab(tab);
            return (84);
        }
    }
    my_free_tab(tab);
    return (0);
}

int wait_event(int flag)
{
    static struct termios save = {0};
    static struct termios modif = {0};
    char nb[1];

    if (flag) {
        ioctl(0, TCGETS, &save);
        ioctl(0, TCGETS, &modif);
        modif.c_lflag &= ~(ICANON);
        modif.c_lflag &= ~(ECHO);
        ioctl(0, TCSETS, &modif);
        read(0, nb, 1);
    } else
        ioctl(0, TCSETS, &save);
    return (0);
}

int main(int ac, char **av)
{
    char **tetrimino_name = NULL;
    arg_t *arg;

    if (ac == 2 && my_strcmp(av[1], "--help") == 0)
        return (help(av[0]));
    arg = init_arg();
    if (check_over_arg(ac, av) == 84 || catch_arg(ac, av, arg) == 84 ||
        check_double_key(arg) == 84)
        return (free_struct(arg) == 0 ? 84 : 84);
    if (my_strcmp(arg->debug, "false") != 0) {
        display_arg(arg);
        tetrimino_name = get_tetri(tetrimino_name);
        print_all_tetri(tetrimino_name);
    }
    my_putstr("Press any key to start Tetris\n");
    wait_event(1);
    wait_event(0);
    init_game(arg);
    free_struct(arg);
    my_free_tab(tetrimino_name);
    return (0);
}
