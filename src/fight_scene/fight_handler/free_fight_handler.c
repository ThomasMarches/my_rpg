/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "fight_scene/fight_handler.h"
#include <stdlib.h>

void rpg_fight_handler_free_extend(void *ptr)
{
    fight_handler_t *fight_handler = NULL;
    game_object_t *tmp = NULL;
    game_object_t *tmp2 = NULL;

    if (ptr == NULL)
        return;
    fight_handler = (fight_handler_t *) ptr;
    rpg_fight_log_destroy(fight_handler);
    if (fight_handler->id != NULL)
        free(fight_handler->id);
    for (tmp = fight_handler->button; tmp;) {
        sfSprite_destroy(tmp->sprite);
        sfTexture_destroy(tmp->texture);
        tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }
    free(fight_handler);
}