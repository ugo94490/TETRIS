/*
** EPITECH PROJECT, 2019
** Library
** File description:
** Transform a string into clean string given delimiters..
*/

#include <stddef.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

static size_t get_clean_size(char const *str, char const *del);
static bool end_word(char const c, char const *del);

char *clean_str(char const *src, char const *del)
{
    size_t size = get_clean_size(src, del);
    char const *srccpy = src;
    char *dest = NULL;
    char *destcpy = NULL;
    uint8_t flag = 0;

    if (!size || !(dest = malloc(sizeof(char) * (size + 1))))
        return NULL;
    dest[size] = '\0';
    destcpy = dest;
    while (*srccpy && destcpy) {
        flag += (srccpy == src ? 0 : 1);
        for (; *srccpy && end_word(*srccpy, del); ++srccpy);
        (flag && size && *srccpy && (srccpy != src) &&
        end_word(*(srccpy - 1), del)) ? *(destcpy++) = *(srccpy - 1) : 0;
        for (;*srccpy && !end_word(*srccpy, del); ++srccpy)
            *(destcpy++) = *srccpy;
    }
    return dest;
}

static size_t get_clean_size(char const *str, char const *del)
{
    size_t i = 0;
    char const *strcpy = str;

    while (*strcpy) {
        for (; *strcpy && end_word(*strcpy, del); ++strcpy);
        i += (i && *strcpy && (strcpy != str) &&
        end_word(*(strcpy - 1), del)) ? 1 : 0;
        for (;*strcpy && !end_word(*strcpy, del); ++strcpy)
            i += 1;
    }
    return i;
}

static bool end_word(char const c, char const *del)
{
    for (; *del; del += 1) {
        if (c == *del)
            return true;
    }
    return false;
}
