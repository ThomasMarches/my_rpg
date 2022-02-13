/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** exit_button_fonction
*/

#include "my_rpg.h"

bool exit_button_function(game_object_t *object, void *pt)
{
    scene_t *scene = (scene_t *)pt;

    scene->display = -1;
    return (true);
    sfRenderWindow_close(scene->window);
}