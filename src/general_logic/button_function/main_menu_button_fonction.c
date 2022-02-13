/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_menu_button_fonction
*/

#include "my_rpg.h"

bool main_menu_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = MAIN_MENU_SCENE;
    return (false);
}