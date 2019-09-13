/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** clock_fcts
*/

#include <time.h>

void reinit_clock(clock_t *to_reinit)
{
    *to_reinit = clock();
}

clock_t get_actual_time(clock_t last_reinit)
{
    return (clock() - last_reinit);
}
