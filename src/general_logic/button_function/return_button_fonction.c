/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main_menu_button_fonctions
*/

#include "my_rpg.h"

bool return_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = MAIN_MENU_SCENE;
    return (true);
}