/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "fight_scene/fight_handler.h"

void rpg_fight_handler_draw(sfRenderWindow *window, game_object_t *object)
{
    fight_handler_t *handler = NULL;
    game_object_t *tmp = NULL;

    handler = (fight_handler_t *) object->extend;
    if (handler->button != NULL)
        tmp = handler->button;
    for (; tmp; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawText(window, handler->fight_log[i], NULL);
}