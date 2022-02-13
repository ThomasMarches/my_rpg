/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_hud_update
*/

#include "galaxie/galaxie_hud.h"
#include "components/text_handler/text_handler.h"
#include "my.h"
#include <stdlib.h>

static void galaxie_hud_update_player_pos(galaxie_hud_t *hud,
scene_t *scene)
{
    game_object_t *tmp = scene->objects_list;
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(scene->window));
    text_handler_t *text = (hud->player_pos) ? hud->player_pos->extend : NULL;
    char *str1 = NULL;
    char *str2 = NULL;

    pos = (sfVector2f) {pos.x - 1920 / 2, pos.y - 1080 / 2};
    if (text)
        sfText_setPosition(text->text, pos);
    for (; tmp && tmp->type != PLAYER; tmp = tmp->next);
    if (!tmp)
        return;
    str1 = my_strcat_nbr("", tmp->pos.x);
    str2 = my_strcat(str1, " / ");
    free(str1);
    str1 = my_strcat_nbr(str2, tmp->pos.y);
    free(str2);
    if (text)
        sfText_setString(text->text, str1);
    free(str1);
}

bool galaxie_hud_update(game_object_t *object, scene_t *scene)
{
    galaxie_hud_t *hud = object->extend;
    game_object_t * tmp = scene->objects_list;
    game_object_t * tmp2 = scene->objects_list;

    if (hud->button && hud->button->update)
        hud->button->update(hud->button, scene);
    for (; tmp && tmp->type != INVENTORY; tmp = tmp->next);
    if (tmp && tmp->state == 1)
        object->state = 0;
    for (; tmp2 && tmp2->type != QUEST_BOARD; tmp2 = tmp2->next);
    if (tmp2 && tmp2->state == 1)
        object->state = 0;
    galaxie_hud_update_player_pos(hud, scene);
    return (true);
}