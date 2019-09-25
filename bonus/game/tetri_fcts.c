/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetri_fcts
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "tetris.h"
#include "game.h"

int get_list_len(link_t *list)
{
    int i = 0;

    for (; list != NULL; i++)
        list = list->next;
    return (i);
}

char **copy_words(char **words, int arg)
{
    int i = 0;
    int j = 0;
    char **copy;

    for (; words[i] != NULL; i++);
    copy = malloc(sizeof(char*) * (i+1+arg));
    if (copy == NULL)
        exit(84);
    copy[i] = NULL;
    for (i = 0; words[i] != NULL; i++) {
        copy[i] = malloc(sizeof(char)* (my_strlen(words[i])+1));
        if (copy[i] == NULL)
            exit(84);
    }
    for (i = 0; words[i] != NULL; i++) {
        for (j = 0; words[i][j] != '\0'; j++)
            copy[i][j] = words[i][j];
        copy[i][j] = '\0';
    }
    return (copy);
}

info_t *copy_tetrimino(info_t *to_copy)
{
    info_t *cpy = malloc(sizeof(info_t));

    cpy->width = to_copy->width;
    cpy->height = to_copy->height;
    cpy->color = to_copy->color;
    cpy->ret = to_copy->ret;
    cpy->x = 0;
    cpy->y = 0;
    cpy->tetri = copy_words(to_copy->tetri, 0);
    return (cpy);
}

info_t *get_tetri_from_list(game_t *game)
{
    link_t *cpy = game->tetriminos;
    int len = get_list_len(game->tetriminos);
    int randomnb = rand()%len;

    for (int i = 0; i < randomnb; i++)
        cpy = cpy->next;
    return (copy_tetrimino(cpy->info));
}
