/*
** EPITECH PROJECT, 2019
** linked
** File description:
** linked.c
*/

#include "tetris.h"

void add_node(char *str, link_t **link)
{
    link_t *node = malloc(sizeof(*node));

    if (*link == NULL) {
        *link = node;
        node->info = malloc(sizeof(info_t));
        get_file(node->info, str);
        (*link)->next = NULL;
    } else {
        while ((*link)->next != NULL)
            (*link) = (*link)->next;
        node->info = malloc(sizeof(info_t));
        get_file(node->info, str);
        node->next = NULL;
        (*link)->next = node;
    }
}

link_t *create_linked(link_t *link)
{
    char **tab = NULL;

    tab = get_tetri(tab);
    if (my_strlen_tab(tab) <= 0)
        return (NULL);
    tab = tetri_sort(tab);
    for (int i = 0; tab[i]; i++) {
        add_node(tab[i], &link);
    }
    return (link);
}
