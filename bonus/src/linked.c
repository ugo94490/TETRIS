/*
** EPITECH PROJECT, 2019
** linked
** File description:
** linked.c
*/

#include "tetris.h"

void add_node(char *str, link_t **link)
{
    link_t *node;

    node = malloc(sizeof(link_t));
    node->info = malloc(sizeof(info_t));
    if (get_file(node->info, str) == 84 ||
    node->info->ret == 84 || node->info->color >= 6) {
        free(node->info);
        free(node);
        return;
    }
    node->next = *link;
    *link = node;
}

void create_linked(link_t **link)
{
    char **tab = NULL;
    char **tab2 = NULL;
    FILE *stream = NULL;

    tab = get_tetri(tab);
    if (my_strlen_tab(tab) <= 0)
        return;
    tab2 = tetri_sort(tab);
    for (int i = 0; tab2[i]; i++) {
        stream = fopen(tab2[i], "r");
        if (stream != NULL) {
            add_node(tab2[i], link);
            fclose(stream);
        }
    }
    my_free_tab(tab);
    my_free_tab(tab2);
}

int display_name(char *str)
{
    int nb = 0;

    str = str + 11;
    nb = my_strlen(str) - 10;
    str[nb] = '\0';
    my_putstr(str);
    return (0);
}
