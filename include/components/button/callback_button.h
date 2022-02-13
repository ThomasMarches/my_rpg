/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** callback_button
*/

#ifndef CALLBACK_BUTTON_H_
#define CALLBACK_BUTTON_H_

#include "my_game.h"

enum {
    PLAY_BUTTON_CALLBACK,
    OPTIONS_BUTTON_CALLBACK,
    INFOS_BUTTON_CALLBACK,
    EXIT_BUTTON_CALLBACK,
    RETURN_BUTTON_CALLBACK,
    MAIN_MENU_BUTTON_CALLBACK,
    RESTART_BUTTON_CALLBACK,
    MAX_CALLBACK_ID_BUTTON
};

bool play_button_function(game_object_t *, void *);
bool options_button_function(game_object_t *, void *);
bool exit_button_function(game_object_t *, void *);
bool infos_button_function(game_object_t *, void *);
bool return_button_function(game_object_t *, void *);
bool main_menu_button_function(game_object_t *, void *);
bool restart_button_function(game_object_t *object, void *pt);

static bool (*BUTTON_CALLBACK_PT[]) (game_object_t *, void *) = {
    &play_button_function,
    &options_button_function,
    &infos_button_function,
    &exit_button_function,
    &return_button_function,
    &main_menu_button_function,
    &restart_button_function
};

#endif /* !CALLBACK_BUTTON_H_ */
