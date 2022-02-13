/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** move_event
*/

#include "my_game.h"
#include "player.h"
#include "galaxie/galaxie_hud.h"
#include "my_rpg.h"

static bool galaxie_button_callback(scene_t *scene, sfRenderWindow *window)
{
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window,
    sfMouse_getPositionRenderWindow(window), sfRenderWindow_getView(window));
    game_object_t *tmp = NULL;
    galaxie_hud_t *hud = NULL;

    for (tmp = scene->objects_list; tmp && tmp->type != GALAXIE_HUD;
    tmp = tmp->next);
    if (!tmp)
        return (false);
    hud = tmp->extend;
    if (tmp->state && sfIntRect_contains(&hud->button->box, pos.x, pos.y))
        scene->display = VILLAGE_SCENE;
    return (false);
}

void galaxie_move_event(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window)
{
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window,
    sfMouse_getPositionRenderWindow(window), sfRenderWindow_getView(window));
    player_t *player_s = NULL;
    game_object_t *tmp = scene->objects_list;
    game_object_t *tmp2 = scene->objects_list;

    for (; tmp && tmp->type != INVENTORY; tmp = tmp->next);
    for (; tmp2 && tmp2->type != QUEST_BOARD; tmp2 = tmp2->next);
    if ((tmp && tmp->state == 1) || (tmp2 && tmp2->state == 1))
        return;
    tmp = scene->objects_list;
    for (tmp = scene->objects_list; tmp && tmp->type != PLAYER;
    tmp = tmp->next);
    if (!tmp)
        return;
    player_s = tmp->extend;
    if (player_s != NULL)
        player_s->galaxie_dest = pos;
    galaxie_button_callback(scene, window);
}