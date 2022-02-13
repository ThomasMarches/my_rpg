/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_check_box
*/

#include "options_menu/check_box.h"

static void rpg_toggle_window_mode(scene_t *scene, int state)
{
    game_t *game = scene->game;

    sfRenderWindow_destroy(scene->window);
    if (state == ON)
        game->window->window = make_window(game->window, sfFullscreen);
    else
        game->window->window = make_window(game->window, sfDefaultStyle);
    scene->window = game->window->window;
}

bool rpg_check_box_update(game_object_t *object, scene_t *scene)
{
    static bool state = OFF;

    if (object->state != state) {
        rpg_toggle_window_mode(scene, object->state);
        state = (object->state) ? ON : OFF;
        sfSprite_setTextureRect(object->sprite,
        *(object->anim[0].frames_key[object->state]));
    }
    return (update_appearing_object(object, scene));
}