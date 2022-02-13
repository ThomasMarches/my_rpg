/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** object_alpha
*/

#include "my_game.h"

void init_appearing_object(game_object_t *object)
{
    object->sprite_color = sfSprite_getColor(object->sprite);
    object->sprite_color.a = 0;
    sfSprite_setColor(object->sprite, object->sprite_color);
}

bool update_appearing_object(game_object_t *object, scene_t *scene)
{
    int alpha = object->sprite_color.a;

    alpha += 20;
    if (alpha > 255)
        object->sprite_color.a = 255;
    else
        object->sprite_color.a = alpha;
    sfSprite_setColor(object->sprite, object->sprite_color);
    return (true);
}

void update_disappearing_object(game_object_t *object)
{
    int alpha = object->sprite_color.a;

    alpha -= 20;
    if (alpha < 0)
        object->sprite_color.a = 0;
    else
        object->sprite_color.a = alpha;
    sfSprite_setColor(object->sprite, object->sprite_color);
}