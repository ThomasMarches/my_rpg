/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** disappear_scene
*/

#include "my_game.h"
#include "my_game/framerate.h"
#include "my_game/scene.h"

bool disappear_scene_objects(scene_t *scene)
{
    game_object_t *object = scene->objects_list;
    bool all_disappear = true;

    while (object) {
        if (object->sprite_color.a != 0) {
            update_disappearing_object(object);
            all_disappear = false;
        }
        object = object->next;
    }
    return (all_disappear);
}

void disappear_scene(scene_t *scene, sfRenderWindow *window, sfClock *clock, \
game_t *game)
{
    static float frame = 0.0;
    static float accumulator = 0.0;
    bool is_closed = false;

    while (!is_closed) {
        frame = sfClock_getElapsedTime(clock).microseconds / SECOND_IN_MICRO;
        sfClock_restart(clock);
        if (frame > MAX_FRAME_RANGE)
            frame = MAX_FRAME_RANGE;
        accumulator += frame;
        while (accumulator >= DELAY_BETWEEN_UPDATE && is_closed == false) {
            is_closed = disappear_scene_objects(scene);
            accumulator -= DELAY_BETWEEN_UPDATE;
        }
        display_scene(scene, window);
        sfRenderWindow_display(window);
    }
}