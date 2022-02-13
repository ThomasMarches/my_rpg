/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** general_function_scene
*/

#include "my_game/scene.h"
#include "my_game/game_object.h"

void check_if_event_is_bind(sfEvent event, game_t *game,
scene_t *scene, sfRenderWindow *window)
{
    for (bind_event_t *tmp = scene->binds_list; tmp; tmp = tmp->next) {
        if (tmp->id == event.type)
            tmp->bind(event, game, scene, window);
    }
}

void handle_scene_event(scene_t *scene, game_t *game, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_if_event_is_bind(event, game, scene, window);
    }
}

void update_scene(scene_t *scene, game_t *game)
{
    update_objects(scene, scene->objects_list, game);
}