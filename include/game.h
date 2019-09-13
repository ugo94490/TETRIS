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
    arg_t *arg;
    char **map;
    link_t *tetriminos;
    info_t *actual_tetrimino;
    info_t *next_tetrimino;
} game_t;

char *my_strappend(char *str, char c);
int get_nb_words(char **arr);
void free_word_array(char **arr);
link_t *create_linked(link_t *link);
char **rotate_arr(char **arr);
int get_nb_words(char **words);
void print_game(game_t *game);
void move_tetr_left(game_t *game, info_t *tetrimino);
void move_tetr_right(game_t *game, info_t *tetrimino);
void move_tetr_down(game_t *game, info_t *tetrimino);

#endif
