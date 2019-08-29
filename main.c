/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <sys/sysmacros.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strcat(char *dest, const char *src)
{
    int len = my_strlen(dest);
    int a = my_strlen(src);
    int i = 0;

    while (i < a + 1) {
        dest[len] = src[i];
        i++;
        len++;
    }
    dest[len - 1] = '\0';
    return dest;
}

int my_strcmp(char const *s1, char const *s2)
{
    int s1_lenght = 0;
    int s2_lenght = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        s1_lenght++;
    for (int i = 0; s2[i] != '\0'; i++)
        s2_lenght++;
    if (s1_lenght > s2_lenght)
        return (1);
    if (s1_lenght < s2_lenght)
        return (2);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (-1);
        if (s1[i] < s2[i])
            return (-2);
    }
    return (0);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0 ; src[i] != '\0' ; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

void my_putstr(char const *str)
{
    write(1, &str, my_strlen(str));
}

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char* dest;

    dest = malloc(sizeof(char) * len);
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
    char *str;

    str = malloc(sizeof(char) * (my_strlen(files) + my_strlen(name) + 3));
    str = my_strcpy(str, files);
    if (files[my_strlen(files) - 1] != '/')
        str = my_strcat(str, "/");
    str = my_strcat(str, name);
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
        copy[0] = malloc(sizeof(char) * (my_strlen(buffer) + 1));
        copy[0] = my_strcpy(copy[0], buffer);
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
    for (int i = 0; i < my_strlen_tab(tab); i++)
        my_putstr(tab[i]);
    return (0);
}

int help(void)
{
    my_putstr("Usage:  ./tetris [options]\nOptions:\n");
    my_putstr(" --help                  Display this help\n");
    my_putstr(" -L --level={num}        Start Tetirs at level num (def: 1)\n");
    my_putstr(" -l --key-left={K}    Move the tetrimino LEFT using the K key"
           " (def: left arrow)");
    my_putstr(" -r --key-right={K}   Move the tetrimino RIGHT using the K key"
           " (def: right arrow)");
    my_putstr(" -t --key-turn={K}    TURN the tetrimino clockwise 90d using"
           " the K key (def: toparrow)");
    my_putstr(" -d --key-drop={K}    DROP the tetrimino using the K key (def:"
           " down arrow)");
    my_putstr(" -q --key-quit={K}    QUIT the game using the K key (def: ‘q’"
           " key)");
    my_putstr(" -p --key-pause={K}   PAUSE/RESTART the game using the K key "
           "(def: space bar)");
    my_putstr(" --map-size={row,col} Set the numbers of rows and columns of "
           "the map (def: 20,10)");
    my_putstr(" -w --without-next    Hide next tetrimino (def: false)");
    my_putstr(" -D --debug           Debug mode (def: false)");
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

int check_name(char *str)
{
    str = my_revstr(str);
    if (my_strncmp("onimirtet.", str, 10) != 0)
        return (84);
    return (0);
}

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
            printf("tab = %s, %s\n", tab[0], tab[1]);
        } else
            free(tmp);
        tmp = NULL;
    }
    closedir(directory);
    return (tab);
}

int main(int ac, char **av)
{
    char **tetrimino_name = NULL;

    if (ac == 2 && my_strcmp(av[1], "--help") == 0)
        return (help());
    tetrimino_name = get_tetri(tetrimino_name);
    print_array(tetrimino_name);
    my_free_tab(tetrimino_name);
    return (0);
}
