/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "tetris.h"

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
        if ((tetrimino_name = get_tetri(tetrimino_name)) == NULL)
            return (84);
        display_arg(arg);
        print_all_tetri(tetrimino_name);
    }
    return (tetris(tetrimino_name, arg));
}
