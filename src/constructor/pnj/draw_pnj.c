/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_pnj_from_conf.c
*/

#include "components/pnj/pnj.h"
#include "my_game.h"
#include "my_json.h"
#include "components/get_from_config.h"

void rpg_draw_pnj(sfRenderWindow *window, game_object_t *object)
{
    pnj_t *pnj = (pnj_t *) object->extend;

    sfRenderWindow_drawSprite(window, object->sprite, NULL);
    if (pnj->draw_text == 1) {
        if (pnj->background != NULL && pnj->background->sprite != NULL && \
        pnj->background->texture != NULL)
            sfRenderWindow_drawSprite(window, pnj->background->sprite, NULL);
        if (pnj->dialog_text != NULL)
            sfRenderWindow_drawText(window, pnj->dialog_text, NULL);
    }
}