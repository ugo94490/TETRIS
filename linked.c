/*
** EPITECH PROJECT, 2019
** linked
** File description:
** linked.c
*/

void add_node(char *str, info_t **info)
{
    info_t *new = malloc(sizeof(*new));

    if (*info == NULL) {
        get_file(new, str);
        *info = new;
    } else {
        while ((*info)->next != NULL)
            (*info) = (*info)->next;
        get_file(new, str);
        new->next = NULL;
        (*info)->next = new;
    }
}

info_t *create_linked(info_t *info)
{
    char **tab = NULL;

    tab = get_tetri(tab);
    if (nb_tetri(tab) == 84)
        return (NULL);
    tab = tetri_sort(tab);
    for (int i = 0; tab[i]; i++) {
        add_node(tab[i], &info);
    }
    return (info);
}
