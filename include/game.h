/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** game header
*/

#ifndef GAME_H
#define GAME_H

typedef struct game_s
{
} game_t;

char *my_strappend(char *str, char c);
int get_nb_words(char **arr);
void free_word_array(char **arr);
link_t *create_linked(link_t *link);
char **rotate_arr(char **arr);
int get_nb_words(char **words);

#endif
