/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "tetris.h"

int tetri(char **tab)
{
    int ret = 0;
    info_t *info = malloc(sizeof(info_t));

    for (int i = 0; tab[i]; i++) {
        set_struct(info);
        printf("Tetriminos :  Name %s :  ", tab[i] + 11);
        get_file(info, tab[i]);
        display(info);
        if (info->ret == 84)
            ret = 84;
        reset_struct(info);
    }
    free(info);
    return (ret);
}

arg_t *init_arg(void)
{
    arg_t *arg = malloc(sizeof(arg_t));

    arg->level = 1;
    arg->key_left = my_strdup("left arrow");
    arg->key_right = my_strdup("right arrow");
    arg->key_turn = my_strdup("top arrow");
    arg->key_drop = my_strdup("down arrow");
    arg->key_quit = my_strdup("q");
    arg->key_pause = my_strdup("left arrow");
    arg->map_x = 10;
    arg->map_y = 20;
    arg->hide = my_strdup("false");
    arg->debug = my_strdup("false");
    return (arg);
}

int free_struct(arg_t *arg)
{
    arg->key_left != NULL ? free(arg->key_left) : 0;
    arg->key_right != NULL ? free(arg->key_right) : 0;
    arg->key_turn != NULL ? free(arg->key_turn) : 0;
    arg->key_drop != NULL ? free(arg->key_drop) : 0;
    arg->key_quit != NULL ? free(arg->key_quit) : 0;
    arg->key_pause != NULL ? free(arg->key_pause) : 0;
    arg->hide != NULL ? free(arg->hide) : 0;
    arg->debug != NULL ? free(arg->debug) : 0;
    free(arg);
    return (0);
}

int catch_arg(int ac, char **av, arg_t *arg)
{
    for (int i = 1; i < ac; i++);
    return (0);
}

int print_two(char *s1, char *s2)
{
    my_putstr(s1);
    my_putstr(s2);
    my_putstr("\n");
    return (0);
}

int display_arg(arg_t *arg)
{
    my_putstr("*** DEBUG MODE ***\n");
    print_two("Key Left :  ", arg->key_left);
    print_two("Key Right :  ", arg->key_right);
    print_two("Key Turn :  ", arg->key_turn);
    print_two("Key Drop :  ", arg->key_drop);
    print_two("Key Quit :  ", arg->key_quit);
    print_two("Key Pause :  ", arg->key_pause);
    print_two("Next :  ", arg->hide);
    printf("Level :  \n");
    printf("Size :  %d*%d\n", arg->map_y, arg->map_x);
    return (0);
}

int main(int ac, char **av)
{
    char **tetrimino_name = NULL;
    arg_t *arg;

    if (ac == 2 && my_strcmp(av[1], "--help") == 0)
        return (help(av[0]));
    arg = init_arg();
    if (catch_arg(ac, av, arg) == 84) {
        free_struct(arg);
        return (84);
    }
    display_arg(arg);
    tetrimino_name = get_tetri(tetrimino_name);
    print_all_tetri(tetrimino_name);
    printf("Press any key to start Tetris\n");
    free_struct(arg);
    my_free_tab(tetrimino_name);
    return (0);
}
