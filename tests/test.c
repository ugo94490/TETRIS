/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** t_solver.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "tetris.h"

Test(tetris, help)
{
    int nb = help("./tetris");

    cr_assert_eq(nb, 0);
}

Test(tetris, over)
{
    int ac = 4;
    char **av = malloc(sizeof(char *) * 4);
    int nb = 0;

    av[0] = strdup("./tetris");
    av[1] = strdup("lol");
    av[2] = strdup("mdr");
    av[3] = strdup("-D");
    nb = check_over_arg(ac, av);
    cr_assert_eq(nb, 84);
}

Test(tetris, bad_ac)
{
    int ac = 2;
    char **av = malloc(sizeof(char *) * 4);
    int nb = 0;

    av[0] = strdup("./tetris");
    av[1] = strdup("lol");
    av[2] = strdup("mdr");
    av[3] = strdup("-D");
    nb = check_over_arg(ac, av);
    cr_assert_eq(nb, 84);
}

Test(tetris, bad_tetri)
{
    char **tetrimino_name = NULL;

    tetrimino_name = get_tetri(tetrimino_name);
    cr_assert_neq(tetrimino_name, NULL);
}

Test(tetris, disp)
{
    int nb = 0;
    arg_t *arg;
    int ac = 2;
    char **av = malloc(sizeof(char *) * 2);

    av[0] = my_strdup("./tetris");
    av[1] = strdup("-D");
    arg = init_arg();
    catch_arg(ac, av, arg);
    nb = display_arg(arg);
    cr_assert_eq(nb, 0);
}

Test(tetris, l_arrow)
{
    int nb = 0;
    arg_t *arg;
    int ac = 14;
    char **av = malloc(sizeof(char *) * 14);

    av[0] = my_strdup("./tetris");
    av[3] = strdup("-l");
    av[4] = strdup("left arrow");
    av[5] = strdup("-t");
    av[6] = strdup("left arrow");
    av[7] = strdup("-d");
    av[8] = strdup("left arrow");
    av[9] = strdup("-q");
    av[10] = strdup("left arrow");
    av[11] = strdup("-p");
    av[12] = strdup("left arrow");
    av[13] = strdup("-D");
    av[1] = strdup("-r");
    av[2] = strdup("left arrow");
    arg = init_arg();
    nb = catch_arg(ac, av, arg);
    cr_assert_eq(nb, 0);
}

Test(tetris, r_arrow)
{
    int nb = 0;
    arg_t *arg;
    int ac = 14;
    char **av = malloc(sizeof(char *) * 14);

    av[0] = my_strdup("./tetris");
    av[3] = strdup("-l");
    av[4] = strdup("right arrow");
    av[5] = strdup("-t");
    av[6] = strdup("right arrow");
    av[7] = strdup("-d");
    av[8] = strdup("right arrow");
    av[9] = strdup("-q");
    av[10] = strdup("right arrow");
    av[11] = strdup("-p");
    av[12] = strdup("right arrow");
    av[1] = strdup("-r");
    av[2] = strdup("right arrow");
    av[13] = strdup("-D");
    arg = init_arg();
    nb = catch_arg(ac, av, arg);
    cr_assert_eq(nb, 0);
}

Test(tetris, t_arrow)
{
    int nb = 0;
    arg_t *arg;
    int ac = 14;
    char **av = malloc(sizeof(char *) * 14);

    av[0] = my_strdup("./tetris");
    av[3] = strdup("-l");
    av[4] = strdup("top arrow");
    av[5] = strdup("-t");
    av[6] = strdup("top arrow");
    av[7] = strdup("-d");
    av[8] = strdup("top arrow");
    av[9] = strdup("-q");
    av[10] = strdup("top arrow");
    av[11] = strdup("-p");
    av[12] = strdup("top arrow");
    av[1] = strdup("-r");
    av[2] = strdup("top arrow");
    av[13] = strdup("-D");
    arg = init_arg();
    nb = catch_arg(ac, av, arg);
    cr_assert_eq(nb, 0);
}

Test(tetris, d_arrow)
{
    int nb = 0;
    arg_t *arg;
    int ac = 14;
    char **av = malloc(sizeof(char *) * 14);

    av[0] = my_strdup("./tetris");
    av[3] = strdup("-l");
    av[4] = strdup("down arrow");
    av[5] = strdup("-t");
    av[6] = strdup("down arrow");
    av[7] = strdup("-d");
    av[8] = strdup("down arrow");
    av[9] = strdup("-q");
    av[10] = strdup("down arrow");
    av[11] = strdup("-p");
    av[12] = strdup("down arrow");
    av[1] = strdup("-r");
    av[2] = strdup("down arrow");
    av[13] = strdup("-D");
    arg = init_arg();
    nb = catch_arg(ac, av, arg);
    cr_assert_eq(nb, 0);
}

Test(TETRIS, word_tab)
{
    char **tab = NULL;
    char *str = strdup(" ls        -l        dxs");

    tab = word_tab(str, " ");
    cr_assert_neq(tab, 0);
}

Test(TETRIS, convert)
{
    char *str = strdup("(space)");
    int nb = 0;

    nb = convert_key(str);
    cr_assert_neq(str, 84);
}

Test(TETRIS, convert1)
{
    char *str = strdup("left arrow");
    int nb = 0;

    nb = convert_key(str);
    cr_assert_neq(str, 84);

}

Test(TETRIS, convert2)
{
    char *str = strdup("right arrow");
    int nb = 0;

    nb = convert_key(str);
    cr_assert_neq(str, 84);
}

Test(TETRIS, convert3)
{
    char *str = strdup("down arrow");
    int nb = 0;

    nb = convert_key(str);
    cr_assert_neq(str, 84);
}

Test(TETRIS, convert4)
{
    char *str = strdup("top arrow");
    int nb = 0;

    nb = convert_key(str);
    cr_assert_neq(str, 84);
}

Test(TETRIS, convert5)
{
    char *str = strdup("q");
    int nb = 0;

    nb = convert_key(str);
    cr_assert_neq(str, 84);
}
