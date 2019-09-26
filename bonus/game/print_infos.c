/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** print_infos
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "graphics.h"
#include "systems.h"
#include "tetris.h"
#include "game.h"

static char *sub_print_infos_3(game_t *game, char *nbr)
{
    nbr = my_itoa(game->level, nbr);
    change_text(my_strdup(nbr), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+3)*24, 150));
    change_text(my_strdup("high score:"), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+9)*24, 150));
    nbr = my_itoa(game->high_score, nbr);
}

static char *sub_print_infos_2(game_t *game, char *nbr)
{
    change_text(my_strdup(nbr), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+3)*24, 180));
    change_text(my_strdup("score:"), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+9)*24, 180));
    nbr = my_itoa(game->score, nbr);
    change_text(my_strdup(nbr), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+3)*24, 210));
    change_text(my_strdup("lines:"), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+9)*24, 210));
    nbr = my_itoa(game->lines, nbr);
    change_text(my_strdup(nbr), &(game->text));
    return (nbr);
}

static char *sub_print_infos(game_t *game, char *nbr)
{
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+3)*24, 240));
    change_text(my_strdup("time:"), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+9)*24, 240));
    nbr = my_itoa(game->timer.time.microseconds/1000000/60, nbr);
    change_text(my_strdup(nbr), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+10)*24+6, 240));
    change_text(my_strdup(":"), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+11)*24, 240));
    nbr = my_itoa((game->timer.time.microseconds/1000000)%60, nbr);
    change_text(my_strdup(nbr), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    return (nbr);
}

void print_infos(game_t *game)
{
    char *nbr = malloc(sizeof(char) * 20);
    char *cpy = nbr;

    game->timer.time = sfClock_getElapsedTime(game->timer.clock);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+3)*24, 120));
    change_text(my_strdup("level:"), &(game->text));
    sfRenderWindow_drawText(game->window->window, game->text.text, NULL);
    sfText_setPosition(game->text.text,
    create_vector2f((game->arg->map_x+9)*24, 120));
    sub_print_infos_3(game, nbr);
    sub_print_infos_2(game, nbr);
    sub_print_infos(game, nbr);
    free(cpy);
}
