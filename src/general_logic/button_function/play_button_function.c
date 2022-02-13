/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** play_button_function
*/

#include "my_rpg.h"

bool play_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = GALAXIE_SCENE;
    return (true);
}