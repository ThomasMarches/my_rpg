/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** ennemy_draw.c
*/

#include "fight_scene/ennemy.h"

void rpg_ennemy_draw(sfRenderWindow *window, game_object_t *object)
{
    ennemy_t *ennemy = (ennemy_t *) object->extend;

    if (ennemy == NULL)
        return;
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    if (ennemy->in_fight == 1) {
        sfRenderWindow_drawText(window, ennemy->hp_text, NULL);
        sfRenderWindow_drawText(window, ennemy->shield_text, NULL);
        sfRenderWindow_drawText(window, ennemy->name_text, NULL);
    }
}