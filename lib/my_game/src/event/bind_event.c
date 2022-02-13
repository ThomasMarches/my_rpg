/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** bind_event
*/

#include "my_game/event.h"
#include "my_game/scene.h"
#include <stdlib.h>

void destroy_bind(bind_event_t **list, bind_event_t *bind)
{
    bind_event_t *tmp = *list;

    if (tmp == bind) {
        *list = bind->next;
        free(bind);
        return;
    }
    for (; tmp && tmp->next != bind; tmp = tmp->next);
    if (!tmp)
        return;
    tmp->next = bind->next;
    free(bind);
}

void destroy_binds_list(bind_event_t *list)
{
    while (list)
        destroy_bind(&list, list);
}

void bind_event(scene_t *scene, sfEventType id, void (*bind)(sfEvent,
game_t *, scene_t *, sfRenderWindow *))
{
    bind_event_t *node = malloc(sizeof(bind_event_t));

    node->next = scene->binds_list;
    scene->binds_list = node;
    node->id = id;
    node->bind = bind;
}