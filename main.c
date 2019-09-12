/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "tetris.h"

int set_drop(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0)
        return (assign_drop("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0)
        return (assign_drop("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0)
        return (assign_drop("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0)
        return (assign_drop("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_drop("(space)", arg));
    if (my_strlen(optarg) == 1) {
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
    if (my_strcmp(optarg, "left arrow") == 0)
        return (assign_turn("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0)
        return (assign_turn("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0)
        return (assign_turn("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0)
        return (assign_turn("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_turn("(space)", arg));
    if (my_strlen(optarg) == 1) {
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
    if (my_strcmp(optarg, "left arrow") == 0)
        return (assign_right("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0)
        return (assign_right("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0)
        return (assign_right("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0)
        return (assign_right("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_right("(space)", arg));
    if (my_strlen(optarg) == 1) {
        free(arg->key_right);
        arg->key_right = my_strdup(optarg);
        return (0);
    }
    return (84);
}

int assign_left(char *str, arg_t *arg)
{
    free(arg->key_left);
    arg->key_left = my_strdup(str);
    return (0);
}

int set_left(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0)
        return (assign_left("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0)
        return (assign_left("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0)
        return (assign_left("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0)
        return (assign_left("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_left("(space)", arg));
    if (my_strlen(optarg) == 1) {
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
        ioctl(0, TCGETS, save);
        ioctl(0, TCGETS, modif);
        modif.c_lflag &= ~(ICANON);
        modif.c_lflag &= ~(ECHO);
        modif.c_cc[VMIN] = 1;
        modif.c_cc[VTIME] = 0;
        ioctl(0, TCSETS, modif);
        read(0, nb, 1);
    } else
        ioctl(0, TCSETS, save);
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
    launch(arg);
    free_struct(arg);
    my_free_tab(tetrimino_name);
    return (0);
}
