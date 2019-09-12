/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** rotate_arr
*/

#include <stdlib.h>

int my_strlen(char const *str);
void free_word_array(char **arr);
char *my_strdup(char const *src);
char *my_strappend(char *str, char c);
int get_nb_words(char **words);

void sub_rotate_arr(char **newarr, char **arr, int nb_words)
{
    for (int y = nb_words-1; y >= 0; y--)
        for (int x = my_strlen(arr[y])-1; x >= 0; x--)
            newarr[x][-(y-(nb_words-1))] = arr[y][x];
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
    sub_rotate_arr(newarr, arr, nb_words);
    free(str);
    free_word_array(arr);
    return (newarr);
}
