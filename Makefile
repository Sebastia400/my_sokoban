##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/my -lmy

SFLAGS = -std=c99 -lncurses

SRC		=	sources/

SRC_C	=	main.c	 		\
			save_map.c		\
			movements.c		\
			search.c		\
			check.c			\
			check2.c			\
			extra_funcs.c	\
			error_handeling.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./include -g

NAME = my_sokoban

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
