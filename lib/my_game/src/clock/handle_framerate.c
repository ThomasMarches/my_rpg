/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** handle_framerate
*/

#include "my_game.h"
#include "my_game/framerate.h"

void handle_framerate(sfClock *clock, scene_t *scene, game_t *game)
{
    static float frame = 0.0;
    static float accumulator = 0.0;

    frame = sfClock_getElapsedTime(clock).microseconds / SECOND_IN_MICRO;
    sfClock_restart(clock);
    if (frame > MAX_FRAME_RANGE)
        frame = MAX_FRAME_RANGE;
    accumulator += frame;
    while (accumulator >= DELAY_BETWEEN_UPDATE) {
        accumulator -= DELAY_BETWEEN_UPDATE;
        if (scene && scene->update_scene != NULL)
            scene->update_scene(scene, game);
    }
}