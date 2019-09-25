/*
** EPITECH PROJECT, 2019
** tools_three.c
** File description:
** tools_three.c
*/

#include "tetris.h"

int my_free_tab(char **tab)
{
    for (int i = 0; i < my_strlen_tab(tab); i++)
        free(tab[i]);
    free(tab);
    return (0);
}

char **tab_realloc(char **tab, char *buffer)
{
    int i = 0;
    char **copy = NULL;

    if (tab == NULL) {
        copy = malloc(sizeof(char *) * (i + 2));
        copy[0] = my_strdup(buffer);
        copy[1] = NULL;
    } else {
        for (i = 0; tab[i] != NULL; i++);
        copy = malloc(sizeof(char *) * (i + 2));
        for (int j = 0; tab[j] != NULL; j++)
            copy[j] = my_strdup(tab[j]);
        copy[i] = my_strdup(buffer);
        copy[i + 1] = NULL;
    }
    if (tab != NULL)
        my_free_tab(tab);
    free(buffer);
    return (copy);
}

char **my_arraycpy(char **tab)
{
    char **copy = malloc(sizeof(char *) * (my_strlen_tab(tab) + 1));

    for (int i = 0; i < my_strlen_tab(tab); i++)
        copy[i] = my_strdup(tab[i]);
    copy[my_strlen_tab(tab)] = NULL;
    return (copy);
}

int print_array(char **tab)
{
    if (tab == NULL)
        return (84);
    for (int i = 0; i < my_strlen_tab(tab); i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
    return (0);
}

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    int tmp = 0;
    int index = 0;

    while (index <= len / 2) {
        tmp = str[index];
        str[index] = str[len - index];
        str[len - index] = tmp;
        index++;
    }
    return (str);
}
