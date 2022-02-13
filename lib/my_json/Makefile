##
## EPITECH PROJECT, 2019
## CPool_infinadd_2019
## File description:
## Makefile
##

FILES = $(shell find ./src/ -iname "*.c")

SRC = $(FILES:./src/%=src/%)

NAME = libmy_json.a

OBJ	=	$(SRC:.c=.o)

LIB = -L./ -lmy

CFLAGS += -Wextra -I./include -g3

DEBUG += -W -Wall -Wextra -pedantic -g3

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)
	mv $(NAME) ../
	cp include/* ../../include

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