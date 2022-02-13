/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** continue_buttons_fonctions
*/

#include "my_rpg.h"

bool continue_button_village_function(game_object_t *object, void *pt)
{
    scene_t *scene = pt;

    scene->display = VILLAGE_SCENE;
    return (true);
}
