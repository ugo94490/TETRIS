/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "tetris.h"

static struct option long_opt[11] = {
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'q'},
    {"key-pause", required_argument, NULL, 'p'},
    {"map-size", required_argument, NULL, 'm'},
    {"without-next", no_argument, NULL, 'w'},
    {"debug", no_argument, NULL, 'D'},
    {0, 0, 0, 0}
};

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
    arg->key_pause = my_strdup("(space)");
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
    printf("Level :  %d\n", arg->level);
    printf("Size :  %d*%d\n", arg->map_y, arg->map_x);
    return (0);
}

int set_hide_o_debug(int nb, arg_t *arg)
{
    if (nb == 'w') {
        if (arg->hide != NULL)
            free(arg->hide);
        arg->hide = my_strdup("true");
    }
    if (nb == 'D') {
        if (arg->debug != NULL)
            free(arg->debug);
        arg->debug = my_strdup("true");
    }
    return (0);
}

int check_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] > '9' || str[i] < '0')
            return (84);
    return (0);
}

int check_size(arg_t *arg)
{
    char *buffer = my_strdup(optarg);
    char **tab = word_tab(buffer, ",");

    if (my_strlen_tab(tab) != 2) {
        my_free_tab(tab);
        free(buffer);
        return (84);
    }
    if (check_number(tab[0]) == 84 || check_number(tab[1]) == 84) {
        my_free_tab(tab);
        free(buffer);
        return (84);
    }
    arg->map_y = my_getnbr(tab[0]);
    arg->map_x = my_getnbr(tab[1]);
    my_free_tab(tab);
    free(buffer);
    return (0);
}

int set_map_size(arg_t *arg)
{
    if (check_size(arg) == 84)
        return (84);
    return (0);
}

int assign_pause(char *str, arg_t *arg)
{
    free(arg->key_pause);
    arg->key_pause = my_strdup(str);
    return (0);
}

int set_pause(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0)
        return (assign_pause("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0)
        return (assign_pause("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0)
        return (assign_pause("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0)
        return (assign_pause("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_pause("(space)", arg));
    if (my_strlen(optarg) == 1) {
        free(arg->key_pause);
        arg->key_pause = my_strdup(optarg);
        return (0);
    }
    return (84);
}

int assign_quit(char *str, arg_t *arg)
{
    free(arg->key_quit);
    arg->key_quit = my_strdup(str);
    return (0);
}

int set_quit(arg_t *arg)
{
    if (my_strcmp(optarg, "left arrow") == 0)
        return (assign_quit("left arrow", arg));
    if (my_strcmp(optarg, "right arrow") == 0)
        return (assign_quit("right arrow", arg));
    if (my_strcmp(optarg, "down arrow") == 0)
        return (assign_quit("down arrow", arg));
    if (my_strcmp(optarg, "up arrow") == 0)
        return (assign_quit("up arrow", arg));
    if (my_strcmp(optarg, " ") == 0)
        return (assign_quit("(space)", arg));
    if (my_strlen(optarg) == 1) {
        free(arg->key_quit);
        arg->key_quit = my_strdup(optarg);
        return (0);
    }
    return (84);
}

int assign_drop(char *str, arg_t *arg)
{
    free(arg->key_drop);
    arg->key_drop = my_strdup(str);
    return (0);
}

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
    int nb = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", long_opt, NULL);

    opterr = 0;
    while (nb != -1) {
        if (nb == '?' || fill_arg(nb, arg) == 84)
            return (84);
        nb = getopt_long(ac, av, "L:l:r:t:d:q:p:wD", long_opt, NULL);
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

int main(int ac, char **av)
{
    char **tetrimino_name = NULL;
    arg_t *arg;

    if (ac == 2 && my_strcmp(av[1], "--help") == 0)
        return (help(av[0]));
    arg = init_arg();
    if (check_over_arg(ac, av) == 84 || catch_arg(ac, av, arg) == 84) {
        free_struct(arg);
        return (84);
    }
    if (my_strcmp(arg->debug, "false") == 0)
        return (0);
    display_arg(arg);
    tetrimino_name = get_tetri(tetrimino_name);
    print_all_tetri(tetrimino_name);
    printf("Press any key to start Tetris\n");
    free_struct(arg);
    my_free_tab(tetrimino_name);
    return (0);
}
