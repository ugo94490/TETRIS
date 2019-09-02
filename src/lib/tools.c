/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** tools.c
*/

#include "tetris.h"

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

int alp_srt(char *s1, char *s2)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i]; i++);
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] < s2[i])
        return (-1);
    return (0);
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

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
