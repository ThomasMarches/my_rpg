/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** game_object
*/

#include "my_game.h"
#include <stdlib.h>
#include <stdbool.h>

void init_game_object(game_object_t *object)
{
    object->sprite = NULL;
    object->texture = NULL;
    object->update = NULL;
    object->callback = NULL;
    object->anim = NULL;
    object->sound_effect = NULL;
    object->delta_t = NULL;
    object->move = (sfVector2f) {0, 0};
    object->state = 0;
    object->z_index = 0;
    object->box = (sfIntRect) {0, 0, 0, 0};
    object->pos = (sfVector2f) {0, 0};
    object->last_pos = object->pos;
    object->next = NULL;
    object->type = DECOR;
    object->sprite_color = (sfColor) {0, 0, 0, 0};
    object->draw = &draw_object;
    object->extend = NULL;
    object->free_extend = NULL;
}

game_object_t *create_game_object(game_object_t *last, char *sprite_path, \
sfVector2f pos, object_type type)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    if (object == NULL)
        return (NULL);
    init_game_object(object);
    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(sprite_path, NULL);
    if (object->sprite == NULL || object->texture == NULL)
        return (NULL);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object->pos = pos;
    object->type = type;
    object->next = last;
    sfSprite_setPosition(object->sprite, object->pos);
    return (object);
}

void move_object(game_object_t *object)
{
    object->last_pos = object->pos;
    object->pos.x += object->move.x;
    object->pos.y += object->move.y;
    object->box.left = object->pos.x;
    object->box.top = object->pos.y;
    sfSprite_setPosition(object->sprite, object->pos);
}

void update_objects(scene_t *scene, game_object_t *object, game_t *game)
{
    bool ret = true;
    game_object_t *tmp = object;

    for (; tmp && object; object = tmp, ret = true) {
        if (object->update != NULL)
            ret = object->update(object, scene);
        tmp = object->next;
        if (ret == false)
            destroy_game_object(scene, tmp);
    }
}