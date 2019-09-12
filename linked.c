/*
** EPITECH PROJECT, 2019
** linked
** File description:
** linked.c
*/

void add_node(char *str, next_t **link)
{
    next_t *node = malloc(sizeof(*node));

    if (*link == NULL) {
        *link = node;
        node->info = malloc(sizeof(info_t));
        get_file(node->info, str);
    } else {
        while ((*link)->next != NULL)
            (*link) = (*link)->next;
        node->info = malloc(sizeof(info_t));
        get_file(node->info, str);
        node->next = NULL;
        (*link)->next = node;
    }
}

next_t *create_linked(next_t *link)
{
    char **tab = NULL;

    tab = get_tetri(tab);
    if (nb_tetri(tab) == 84)
        return (NULL);
    tab = tetri_sort(tab);
    for (int i = 0; tab[i]; i++) {
        add_node(tab[i], &link);
    }
    return (link);
}
