/*
** EPITECH PROJECT, 2019
** get.c
** File description:
** get.c
*/

#include "tetris.h"

char **get_tetri(char **tab)
{
    DIR *directory = opendir("./tetriminos");
    char *tmp = NULL;
    struct dirent *file;
    struct stat buffer;

    if (directory == NULL)
        return (NULL);
    while ((file = readdir(directory))) {
        tmp = concat_directory_path("tetriminos/", file->d_name);
        stat(tmp, &buffer);
        if (!S_ISDIR(buffer.st_mode) && check_name(file->d_name) == 0) {
            tab = tab_realloc(tab, tmp);
        } else
            free(tmp);
        tmp = NULL;
    }
    closedir(directory);
    return (tab);
}

int get_nbr(info_t *info, char **tab)
{
    char **first = NULL;

    if (tab == NULL)
        return (info->ret = 84);
    first = word_tab(tab[0], " ");
    for (int i = 0; first[i]; i++)
        if (check_nbr(first[i])) {
            my_free_tab(first);
            return (info->ret = 84);
        }
    info->width = my_getnbr(first[0]);
    info->height = my_getnbr(first[1]);
    info->color = my_getnbr(first[2]);
    my_free_tab(first);
    return (0);
}

int get_shape(info_t *info, char **tab)
{
    char *tmp = NULL;
    char **shp = NULL;

    for (int i = 1; tab[i]; i++) {
        tmp = my_strdup(tab[i]);
        shp = tab_realloc(shp, tmp);
        tmp = NULL;
    }
    if (shp == NULL)
        return (info->ret = 84);
    if (vrf_w(info, shp) == 84 || vrf_h(info, shp) == 84 || vrf_c(info) == 84) {
        my_free_tab(shp);
        return (84);
    }
    info->tetri = my_arraycpy(shp);
    my_free_tab(shp);
    return (0);
}

int get_info(info_t *info, char **tab)
{
    get_nbr(info, tab);
    get_shape(info, tab);
    return (0);
}

int get_file(info_t *info, char *str)
{
    char **tab = NULL;
    FILE *stream = fopen(str, "r");
    int nb = 0;
    char *buffer = NULL;
    size_t len = 0;

    info->ret = 0;
    if (stream == NULL)
        return (84);
    while ((nb = getline(&buffer, &len, stream)) > 0) {
        buffer[nb - 1] = '\0';
        tab = tab_realloc(tab, buffer);
        buffer = NULL;
    }
    fclose(stream);
    free(buffer);
    get_info(info, tab);
    my_free_tab(tab);
    return (0);
}
