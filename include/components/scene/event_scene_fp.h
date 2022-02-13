/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_scene_fp
*/

#ifndef EVENT_SCENE_FP_H_
#define EVENT_SCENE_FP_H_

#include "my_game.h"

enum {
    CLOSE_SCENE_EVENT_ID,
    CLICK_ON_EVENT_ID,
    RETURN_TO_MAIN_MENU_EVENT_ID,
    GALAXIE_MOVE_EVENT_ID,
    TRIGGER_IN_GAME_MENU_EVENT_ID,
    OPEN_INVENTORY_ID,
    FIGHT_PAUSE_ID,
    VILLAGE_MOVE_EVENT_ID,
    OPEN_QUEST_BOARD_ID,
    TRIGGER_IN_GAME_MENU_VILLAGE_EVENT_ID,
    MAX_SCENE_EVENT_ID
};

void return_to_main_menu(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window);
void galaxie_move_event(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window);
void village_move_event(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window);
void trigger_in_game_menu(sfEvent event, game_t *game,
scene_t *scene, sfRenderWindow *window);
void return_to_main_menu(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window);
void open_inventory(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window);
void open_quest_board(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window);
void pause_fight(sfEvent event, game_t *game, scene_t *scene,
sfRenderWindow *window);
void trigger_in_game_menu_village(sfEvent event, game_t *game,
scene_t *scene, sfRenderWindow *window);

static void (*EVENT_SCENE_FP[]) (sfEvent, game_t *, scene_t *,
sfRenderWindow *) = {
    &close_scene,
    &is_click_on_object,
    &return_to_main_menu,
    &galaxie_move_event,
    &trigger_in_game_menu,
    &open_inventory,
    &pause_fight,
    &village_move_event,
    &open_quest_board,
    &trigger_in_game_menu_village
};

#endif /* !EVENT_SCENE_FP_H_ */
