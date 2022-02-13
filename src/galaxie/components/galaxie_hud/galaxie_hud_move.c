/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_hud_move
*/

#include "galaxie/galaxie_hud.h"

int galaxie_hud_move(game_object_t *object, game_object_t *planet)
{
    galaxie_hud_t *hud = object->extend;
    sfFloatRect box = sfSprite_getGlobalBounds(planet->sprite);
    sfVector2f pos = (sfVector2f) {box.left + box.width / 2 -
    hud->button->box.width / 2, box.top + box.height / 2 -
    hud->button->box.height / 2};

    sfSprite_setPosition(hud->button->sprite, pos);
    hud->button->pos = pos;
    hud->button->box.left = pos.x;
    hud->button->box.top = pos.y;
    return (1);
}