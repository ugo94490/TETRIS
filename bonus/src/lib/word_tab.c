/*
** EPITECH PROJECT, 2019
** Library.
** File description:
** Transform a string into an array of string given delimiters.
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tetris.h"

static char *findex(char **str, char const *del, size_t word_len);
static size_t get_nb_line(char const *str, char const *del);
static size_t word_len(char const *str, char const *del);
static bool end_word(char const c, char const *del);
char *clean_str(char const *src, char const *del);

char **word_tab(char const *src, char const *del)
{
    char *str = clean_str(src, del);
    size_t nb_line = get_nb_line(str, del);
    size_t wlen = 0;
    char **tab = NULL;

    if (!nb_line || !del || !(*del) || !str)
        return NULL;
    if (!(tab = malloc(sizeof(char *) * (nb_line + 1))))
        return NULL;
    src = str;
    for (size_t i = 0; i < nb_line; i += 1) {
        wlen = word_len(str, del);
        if ((!wlen && !(tab + i)) || !(*(tab + i) = findex(&str, del, wlen))) {
            free(tab);
            return NULL;
        }
    }
    free((char *)src);
    *(tab + nb_line) = NULL;
    return tab;
}

static char *findex(char **str, char const *del, size_t word_len)
{
    size_t i = 0;
    char *index = malloc(sizeof(char) * (word_len + 1));

    if (!index)
        return NULL;
    for (i = 0; !end_word(**str, del) && **str; i += 1)
        *(index + i) = *((*str)++);
    *(index + i) = '\0';
    for (; end_word(**str, del) && **str; (*str)++);
    return index;
}

static size_t get_nb_line(char const *str, char const *del)
{
    size_t i = 0;

    if (!str)
        return 0;
    for (; *(str + i); end_word(*(str + i), del) ? i += 1 : (size_t)str++);
    return ++i;
}

static size_t word_len(char const *str, char const *del)
{
    size_t len = 0;

    for (len = 0; *(str + len) && !end_word(*(str + len), del); len += 1);
    return len;
}

static bool end_word(char const c, char const *del)
{
    for (; *del; del += 1) {
        if (c == *del)
            return true;
    }
    return false;
}
