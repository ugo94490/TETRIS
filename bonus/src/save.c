/*
** EPITECH PROJECT, 2019
** save.c
** File description:
** save.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "tetris.h"
#include "game.h"

int load_score(void)
{
    FILE *stream = fopen(".highscore", "r");
    char *buffer = NULL;
    size_t len = 0;
    int nb = 0;

    if (stream == NULL)
        return (0);
    nb = getline(&buffer, &len, stream);
    if (nb <= 0)
        return (0);
    else {
        nb = my_getnbr(buffer);
        free(buffer);
        return (nb);
    }
}

int concat(game_t *game, char *nbr, FILE *stream)
{
    char *tmp = NULL;

    nbr = malloc(sizeof(char) * (my_int(game->score) + 1));
    tmp = my_itoa(game->score, nbr);
    fwrite(tmp, 1, my_strlen(tmp), stream);
    free(nbr);
    return (0);
}

int save(game_t *game)
{
    FILE *stream = fopen(".highscore", "w");
    char *nbr = NULL;
    char *buffer = NULL;
    size_t len = 0;
    int nb = 0;

    if (game->score < game->high_score ||
    (stream = fopen(".highscore", "w")) == NULL)
        return (0);
    nb = getline(&buffer, &len, stream);
    if (nb <= 0)
        concat(game, nbr, stream);
    if (nb > 0) {
        nb = my_getnbr(buffer);
        if (game->score > game->high_score)
            concat(game, nbr, stream);
    }
    if (buffer != NULL)
        free(buffer);
    fclose(stream);
    return (0);
}
