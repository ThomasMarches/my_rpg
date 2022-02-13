/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_space_ship.c
*/

#include "my_game.h"
#include "fight_scene/ship.h"

void rpg_space_ship_draw(sfRenderWindow *window, game_object_t *object)
{
    space_ship_t *ship = (space_ship_t *) object->extend;

    if (ship == NULL)
        return;
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    if (ship->in_fight == 1) {
        sfRenderWindow_drawText(window, ship->hp_text, NULL);
        sfRenderWindow_drawText(window, ship->shield_text, NULL);
        sfRenderWindow_drawText(window, ship->action_left, NULL);
        sfRenderWindow_drawText(window, ship->repair_turn_left, NULL);
    }
}