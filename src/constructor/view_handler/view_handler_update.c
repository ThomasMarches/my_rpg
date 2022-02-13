/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** view_handler_update
*/

#include "components/view_handler/view_handler.h"

bool view_handler_update(game_object_t *object, scene_t *scene)
{
    sfView *view = (sfView *) sfRenderWindow_getView(scene->window);
    sfFloatRect view_port = {0, 0, 0, 0};
    view_handler_t *view_default = object->extend;
    sfVector2u size = sfRenderWindow_getSize(scene->window);

    if (view == NULL)
        return (true);
    view_port.height = (view_default->view_port.height *
    (size.x / (float) scene->game->window->width));
    view_port.width = view_default->view_port.width *
    (size.y /(float) scene->game->window->height);
    view_port.left = (1 - view_port.width) / 2.0f;
    view_port.top = (1 - view_port.height) / 2.0f;
    sfView_setViewport(view, view_port);
    sfRenderWindow_setView(scene->window, view);
    return (true);
}