/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_fighthandler.c
*/

#include "my_game.h"
#include "my_rpg.h"
#include "fight_scene/fight_handler.h"
#include "fight_scene/ennemy.h"
#include "fight_scene/ship.h"
#include "player.h"
#include <stdlib.h>

static void rpg_fight_handler_player_lose(game_object_t *object, \
scene_t *scene)
{
    space_ship_t *ship = rpg_spaceship_get_extend(scene);

    if (ship == NULL || ship->hp > 0)
        return;
    scene->display = GALAXIE_SCENE;
}

static void rpg_fight_handler_player_win(game_object_t *object, \
scene_t *scene)
{
    ennemy_t *ennemy = rpg_ennemy_get_extend(scene);
    player_t *player = scene->game->player;

    if (ennemy == NULL || ennemy->hp > 0)
        return;
    if (ennemy->quest_id == player->quest.id)
        validate_step(scene->game, scene, &player->quest);
    scene->display = GALAXIE_SCENE;
}

bool rpg_fight_handler_update(game_object_t *object, scene_t *scene)
{
    fight_handler_t *handler = (fight_handler_t *) object->extend;

    if (handler == NULL || handler->in_fight == 0)
        return (true);
    rpg_fight_handler_player_win(object, scene);
    rpg_fight_handler_player_lose(object, scene);
    handler->action_number = rpg_spaceship_get_equip_size(object, scene);
    if (handler->player_turn == 1 && handler->done == handler->action_number) {
        rpg_fight_handler_make_player_actions(object, scene);
        handler->player_turn = 0;
    } else if (handler->player_turn == 0) {
        rpg_fight_handler_make_ennemy_play(object, scene);
        handler->player_turn = 1;
    }
    return (true);
}