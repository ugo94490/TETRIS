/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game
*/

#include <time.h>
#include "tetris.h"
#include "game.h"

int get_nb_words(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return (0);
    for (; arr[i]; i++);
    return (i);
}

void sub_rotate_arr(char **newarr, char c, int x, int y)
{
    newarr[y][x] = c;
}

char **rotate_arr(char **arr)
{
    int longest_line_len = 0;
    int nb_words = get_nb_words(arr);
    char *str = malloc(sizeof(char));
    char **newarr;

    for (int i = 0; arr && arr[i]; i++)
        if (my_strlen(arr[i]) > longest_line_len)
            longest_line_len = my_strlen(arr[i]);
    newarr = malloc(sizeof(char*) * longest_line_len+1);
    if (newarr == NULL || str == NULL)
        return (NULL);
    str[0] = '\0';
    for (int i = 0; i < nb_words; i++)
        str = my_strappend(str, ' ');
    for (int i = 0; i < longest_line_len; i++)
        newarr[i] = my_strdup(str);
    for (int y = nb_words-1; y >= 0; y--)
        for (int x = my_strlen(arr[y])-1; x >= 0; x--)
            newarr[x][-(y-(nb_words-1))] = arr[y][x];
    free(str);
    return (newarr);
}

char *my_strappend(char *str, char c)
{
    char *newstr = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;

    if (newstr == NULL)
        return (NULL);
    for (; str[i]; i++)
        newstr[i] = str[i];
    newstr[i] = c;
    newstr[i+1] = '\0';
    free(str);
    return (newstr);
}

void free_word_array(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

void print_map(char **map)
{
    printw("+----------+\n");
    for (int i = 0; map[i]; i++)
        printw("|%s|\n", map[i]);
    printw("+----------+\n");
}

void game(arg_t *arg, char **map)
{
    print_map(map);
    getch();
}

char **create_empty_tetris_arr(arg_t *arg)
{
    char **arr = malloc(sizeof(char *) * arg->map_y+1);
    char *str = malloc(sizeof(char));

    if (arr == NULL || str == NULL)
        return (NULL);
    str[0] = '\0';
    for (int i = 0; i < arg->map_x; i++)
        str = my_strappend(str, ' ');
    for (int i = 0; i < arg->map_y+1; i++)
        arr[i] = my_strdup(str);
    arr[arg->map_y] = NULL;
    free(str);
    return (arr);
}

void init_game(arg_t *arg)
{
    char **arr;

    srand(time(0));
    initscr();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    arr = create_empty_tetris_arr(arg);
    if (arr != NULL)
        game(arg, arr);
    free_word_array(arr);
    endwin();
}
