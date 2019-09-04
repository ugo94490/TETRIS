/*
** EPITECH PROJECT, 2019
** tools_two.c
** File description:
** tools_two.c
*/

#include "tetris.h"

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return (0);
}

char *my_strdup(char *src)
{
    int len = my_strlen(src);
    char* dest = NULL;

    dest = malloc(sizeof(char) * (len + 1));
    dest = my_strcpy(dest, src);
    dest[len] = '\0';
    return (dest);
}

int my_strncmp(char *s1, char *s2, int n)
{
    int compteur = 0;

    while ((s1[compteur] == s2[compteur]) && (s1[compteur] && s2[compteur])
        && (compteur < n))
        compteur = compteur + 1;
    if (((s1[compteur] == '\0') && (s2[compteur] == '\0')) || compteur == n)
        return (0);
    else if (s1[compteur] > s2[compteur])
        return (1);
    else
        return (-1);
}

char *concat_directory_path(char *files, char *name)
{
    char *str = NULL;

    str = malloc(sizeof(char) * (my_strlen(files) + my_strlen(name) + 1));
    str = my_strcpy(str, files);
    if (files[my_strlen(files) - 1] != '/')
        str = my_strcat(str, "/");
    str = my_strcat(str, name);
    str[my_strlen(files) + my_strlen(name)] = '\0';
    return (str);
}

int my_strlen_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (i);
    while (tab[i] != NULL)
        i++;
    return (i);
}
