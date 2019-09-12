/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** utils
*/

#include <stdlib.h>

int my_strlen(char const *str);

int get_nb_words(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return (0);
    for (; arr[i]; i++);
    return (i);
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
