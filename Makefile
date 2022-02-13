##
## EPITECH PROJECT, 2019
## bootstap_runner
## File description:
## Makefile
##

CC = gcc

FILES = $(shell find ./src/ -iname "*.c")

TEST_FILES = $(shell find ./src/ -iname "*.c" ! -name "*main.c") $(shell find ./tests/ -iname "*.c")

SRC = $(FILES:./src/%=src/%)

TEST_SRC = $(TEST_FILES:./src/%=src/%)

LIBS_DIR = $(shell find ./lib/ -maxdepth 1 -type d -name "my*")

LIB_NAME = $(LIB:./lib/%=%)

BUILD_DIR = build/

OBJ = $(addprefix $(BUILD_DIR), $(SRC:.c=.o))

TEST_OBJ = $(addprefix $(BUILD_DIR), $(TEST_SRC:.c=.o))

RMD_FILES = $(OBJ) vgcore.* lib/*.a

NAME = my_rpg

CFLAGS = $(LDFLAGS) $(HEADER) -W -Wall -Wextra -pedantic -Wno-newline-eof -Wno-unused-parameter -Wno-unused-command-line-argument -Wno-deprecated $(DEBUG)

LDFLAGS = -L./lib -lm -lmy_game -lmy -lmy_json $(CSFML)

LIBS = $(foreach LIB, $(LIBS_DIR), $(addprefix -l, $(LIB_NAME)))

CSFML = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

HEADER = -I./include

REDDARK	=	\033[31;1m
RED	=	\033[31;1m
GREEN	=	\033[32;1m
YEL	=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[0m

all : $(NAME)

debug:
	$(eval CFLAGS += -g3)
	@printf "$(PINK)[DEBUG]$(WHITE)\n"
	@make BLUE='\033[35;1m' DEBUG='-g3' -s fclean $(NAME)

$(BUILD_DIR)%.o:%.c
	@mkdir -p `dirname  $@`
	@printf "$(GREEN)[$(WHITE)MY_RPG$(GREEN)] — $(BLUE)%-90s" $@
	@printf "$(GREEN)[$(WHITE)√$(GREEN)]\n$(WHITE)"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : make_lib start_compil $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@printf "\n$(GREEN) → Successfully build.  "
	@printf "$(BLUE) Binary :$(CYAN) $(NAME)\n\n$(WHITE)"

start_compil:
	@printf "\n$(GREEN)[$(WHITE)MY_RPG$(GREEN)] — START BUILD\n\n"

make_lib :
	@printf "\n$(GREEN)[$(WHITE)LIB$(GREEN)] — $(YEL)BUILDING LIBS\n\n"
	@$(foreach LIB, $(LIBS_DIR), \
	printf "$(GREEN)[$(WHITE)LIB$(GREEN)] — $(YEL)BUILDING %-84s" $(LIB_NAME) \
	&& make -sC $(LIB) \
	&& printf "$(YEL)[$(WHITE)√$(YEL)]\n$(WHITE)";)
	@printf "\n"

doc :
	@doxygen doxyconf
	@printf "\n$(GREEN)[$(WHITE)LIB$(GREEN)] — $(PURPLE)CREATE DOC$(WHITE)\n\n"

clean :
	@printf "$(REDDARK)\nCleaning build files of \
	$(GREEN)[$(WHITE)MY_RPG$(GREEN)]\n\n"
	@printf "$(GREEN)[$(WHITE)MY_RPG$(GREEN)] — $(RED)%-45s\n" $(OBJ)
	@printf "\n$(GREEN) → $(RED) Build clean.\n\n$(WHITE)"
	@rm -f $(RMD_FILES)

fclean :
	@printf "$(REDDARK)\nCleaning Repository \
	$(GREEN)[$(WHITE)MY_RPG$(GREEN)] \n"
	@make -s clean
	@rm -rf $(BUILD_DIR)
	@printf "$(GREEN)[$(WHITE)MY_RPG$(GREEN)] — $(RED)%-45s\n" $(BUILD_DIR)
	@rm -f $(NAME)
	@$(foreach LIB, $(LIBS_DIR), \
	rm -f $(addsuffix .a, $(addprefix lib/lib, $(LIB_NAME))) && \
	printf "$(GREEN)[$(WHITE)MY_RPG$(GREEN)] — $(RED)%-45s\n" \
	$(addsuffix .a, $(addprefix lib/lib, $(LIB_NAME)));)
	@printf "$(GREEN)[$(WHITE)MY_RPG$(GREEN)] — $(RED)%-45s\n" $(NAME)
	@printf "\n$(GREEN) → $(REDDARK) Repository clean.\n\n$(WHITE)"

re : fclean all

tests_run: LDFLAGS+= -lcriterion
tests_run: CFLAGS+= --coverage
tests_run: make_lib start_compil $(TEST_OBJ)
	@$(CC) -o unit_tests $(TEST_OBJ) $(CFLAGS)
	@printf "\n$(GREEN) → Successfully build.  "
	@printf "$(BLUE) Binary :$(CYAN) unit_tests\n\n$(WHITE)"
