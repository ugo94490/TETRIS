##
## EPITECH PROJECT, 2018
## PSU_tetris_2018
## File description:
## Makefile
##


SRC		=	main.c		\
		src/lib/word_tab.c	\
		src/lib/clean_str.c	\
		src/lib/tools.c		\
		src/lib/tools_two.c	\
		src/lib/tools_three.c	\
		src/lib/print.c		\
		src/help.c		\
		src/tetri/check.c	\
		src/tetri/get.c		\
		src/tetri/sort.c	\
		src/misc.c		\
		src/struct_disp.c	\
		src/disp.c		\
		src/linked.c		\
		game/game.c		\
		game/utils.c		\
		game/rotate_arr.c	\
		game/print_game.c	\
		game/sub_draw_game.c	\
		game/move_tetriminos.c	\
		game/tetri_fcts.c	\
		game/insert_tetri.c	\
		game/analyse_events.c	\
		game/init_destroy_game.c\
		game/clock_fcts.c	\
		game/misc.c		\
		src/assign.c		\
		src/assign_two.c	\
		src/assign_three.c	\
		src/convert.c		\
		src/init.c		\
		src/save.c		\
		src/tools.c		\
		src/new.c		\
		lib_CSFML/window_functions.c	\
		lib_CSFML/clock_functions.c	\
		lib_CSFML/sound_functions.c	\
		lib_CSFML/text_functions.c	\
		lib_CSFML/value_structs.c	\
		lib_CSFML/sprite_functions.c

SRC_T		=	tests/test.c	\
		src/lib/word_tab.c	\
		src/lib/clean_str.c	\
		src/lib/tools.c		\
		src/lib/tools_two.c	\
		src/lib/tools_three.c	\
		src/lib/print.c		\
		src/help.c		\
		src/tetri/check.c	\
		src/tetri/get.c		\
		src/tetri/sort.c	\
		src/misc.c		\
		src/struct_disp.c	\
		src/disp.c		\
		src/linked.c		\
		src/assign.c		\
		src/assign_two.c	\
		src/assign_three.c	\
		src/convert.c		\
		src/init.c		\
		src/save.c		\
		src/tools.c		\

OBJ		=	$(SRC:.c=.o)

OBJ_T		=	$(SRC_T:.c=.o)

NAME		=	tetris

TESTS_NAME	=	unit_tests

CC		=	gcc

CFLAGS		=	-I./include -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-system -lm -I./lib_CSFML/include

CPPFLAGS	+=

TEST_FLAGS	=	-lcriterion --coverage

RM		=	rm -f

$(NAME) 	: 	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

all		:	$(NAME)

tests_run 	:
			@$(CC) $(SRC_T) $(CFLAGS) $(CPPFLAGS) $(TEST_FLAGS) -o $(TESTS_NAME)
			./unit_tests
			gcovr -r . --exclude tests
			gcovr -r . -b --exclude tests
			rm -f unit_tests
			$(RM) *.gc*

clean 		:
			$(RM) $(OBJ)
			$(RM) $(OBJ_T)

tests_clean 	:
			$(RM) tests/*.gcda
			$(RM) tests/*.gcno
			$(RM) *.gc*
			$(RM) tests_run

fclean 		:	clean tests_clean
			$(RM) $(NAME) $(TESTS_NAME)

re		:	fclean all

.PHONY 		:	all clean fclean re tests_run tests_clean
