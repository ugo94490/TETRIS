/*
** EPITECH PROJECT, 2019
** tetris.h
** File description:
** tetris.h
*/

#include <getopt.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/sysmacros.h>
#include <termios.h>
#include <sys/ioctl.h>

static const struct option LONG_OPT[11] = {
    {"level", required_argument, NULL, 'L'},
    {"key-left", required_argument, NULL, 'l'},
    {"key-right", required_argument, NULL, 'r'},
    {"key-turn", required_argument, NULL, 't'},
    {"key-drop", required_argument, NULL, 'd'},
    {"key-quit", required_argument, NULL, 'q'},
    {"key-pause", required_argument, NULL, 'p'},
    {"map-size", required_argument, NULL, 'm'},
    {"without-next", no_argument, NULL, 'w'},
    {"debug", no_argument, NULL, 'D'},
    {0, 0, 0, 0}
};

typedef struct arg_s
{
    int level;
    char *key_left;
    char *key_right;
    char *key_turn;
    char *key_drop;
    char *key_quit;
    char *key_pause;
    int map_x;
    int map_y;
    char *hide;
    char *debug;
}arg_t;

typedef struct info_s
{
    int width;
    int height;
    int color;
    char **tetri;
    int ret;
    int x;
    int y;
}info_t;

typedef struct link_s
{
    info_t *info;
    struct link_s *next;
} link_t;

char *clean_str(char const *src, char const *del);
char **word_tab(char const *src, char const *del);

/* TOOLS.C */
int my_strlen(char const *str);
char *my_strcat(char *dest, const char *src);
int alp_srt(char *s1, char *s2);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char *src);

/* TOOLS_TWO.C */
int my_putstr(char *str);
char *my_strdup(char *src);
int my_strncmp(char *s1, char *s2, int n);
char *concat_directory_path(char *files, char *name);
int my_strlen_tab(char **tab);

/* TOOLS_THREE.C */
int my_free_tab(char **tab);
char **tab_realloc(char **tab, char *buffer);
char **my_arraycpy(char **tab);
int print_array(char **tab);
char *my_revstr(char *str);

/* HELP.C */
int disp_first(char *str);
int help(char *str);

/* CHECK.C */
int check_name(char *str);
int check_nbr(char *c);
int vrf_c(info_t *info);
int check_line(char **str);
int vrf_h(info_t *info, char **shape);

/* GET.C */
char **get_tetri(char **tab);
int get_nbr(info_t *info, char **tab);
int get_shape(info_t *info, char **tab);
int get_info(info_t *info, char **tab);
int get_file(info_t *info, char *str);

/* SORT.C */
int nb_tetri(char **tab);
char **swap(char **files, int i);
char **tetri_sort(char **tab);
int count(char **tmp);
int vrf_w(info_t *info, char **shape);

/* MISC.C */
int my_getnbr(char *str);
int set_struct(info_t *info);
int reset_struct(info_t *info);
int display(info_t *info);
int print_all_tetri(char **tab);

/* MAIN.C */
void init_game(arg_t *arg);
int tetri(char **tab);
int my_putnbr(int nb);
int launch(arg_t *arg);

void add_node(char *str, link_t **link);
link_t *create_linked(link_t *link);
arg_t *init_arg(void);
int free_struct(arg_t *arg);
int disp_arrow(char *pri, char *str);
int disp_level_size(int level, int x, int y);
int display_arg(arg_t *arg);
int set_hide_o_debug(int nb, arg_t *arg);
int check_number(char *str);
int check_size(arg_t *arg);
int set_map_size(arg_t *arg);
int assign_pause(char *str, arg_t *arg);
int set_pause(arg_t *arg);
int assign_quit(char *str, arg_t *arg);
int set_quit(arg_t *arg);
int assign_drop(char *str, arg_t *arg);
