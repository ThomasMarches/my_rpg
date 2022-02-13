##
## EPITECH PROJECT, 2020
## Runner
## File description:
## Makefile
##

CC = gcc

NAME = libmy_game.a

SRC = $(shell find ./src/ -iname "*.c")

OBJ = $(SRC:.c=.o)

CFLAGS = $(CSFML) -I./include -I../my_graph/ -g3

CSFML = -Wno-unused-command-line-argument -Wno-deprecated -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

all : $(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)
	mv $(NAME) ../
	cp -r include/* ../../include
	rm -rf $(OBJ)

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $<