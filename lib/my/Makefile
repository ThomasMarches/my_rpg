##
## EPITECH PROJECT, 2019
## CPool_infinadd_2019
## File description:
## Makefile
##

SRC	=	my_nbr_to_str.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_getnbr.c \
		my_str_to_word_array.c \
		my_putstr.c	\
		my_strndup.c	\
		my_free.c	\
		my_strcat_nbr.c

MAIN = src/main.c

NAME = libmy.a

OBJ	=	$(SRC:.c=.o)

LIB = -L./ -lmy

CFLAGS += -Wextra -I./include

DEBUG += -W -Wall -Wextra -pedantic -g3

all : $(NAME)

$(NAME) : $(OBJ)
	cp my.h ../../include/
	ar rc libmy.a $(OBJ)
	mv $(NAME) ../
	rm -f $(OBJ)

clean :
	rm -f src/*.gc*
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	rm -f print
	rm -f tests/unit_tests

re : fclean all

debug :
	make -C ./ re
	gcc $(MAIN) -o print -I./include $(LIB) $(DEBUG)