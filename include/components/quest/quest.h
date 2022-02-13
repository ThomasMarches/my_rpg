/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quest_handler
*/

#include "my_game.h"
#include "item/item_id.h"
#include "components/quest/board.h"
#include "my_rpg.h"
#include "my_json.h"

#ifndef QUEST_HANDLER_H_
#define QUEST_HANDLER_H_

typedef enum {
    QUEST1,
    QUEST2,
    QUEST3,
    QUEST4,
    MAX_QUEST_ID
} quest_id;

typedef enum {
    UNTAKEN,
    TAKEN,
    ACHIEVED,
    RESET
} quest_state;

typedef enum {
    DIALOG,
    FIGHT,
    REACH
} step_type;

typedef struct step {
    sfVector2f pos;
    step_type step_type;
    int step_number;
    bool validated;
    char *description;
    char *fight_scene;
    scene_index scene;
    struct step *next;
} step_t;

typedef struct quest {
    quest_state state;
    char *name;
    int number_of_step;
    int reward_money;
    int actual_step;
    item_id reward_item;
    int reward_item_number;
    struct step *step;
    quest_id id;
} quest_t;

step_t *rpg_quest_load_step_from_conf(json_object_t *js);
void validate_step(game_t *game, scene_t *scene, quest_t *quest);
void validate_quest(game_t *game, scene_t *scene, quest_t *quest);
void rpg_destroy_quest(quest_t *quest);
quest_t rpg_quest_get_from_conf(char *path, scene_t *scene);
void rpg_quest_board_draw(sfRenderWindow *window, game_object_t *object);
quest_board_t *rpg_quest_board_create_extend(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene);
quest_board_t *rpg_quest_board_init_text_step(step_t *tmp, \
quest_board_t *board);
quest_board_t *rpg_quest_board_init_text(game_t *game, step_t *tmp, \
quest_board_t *board);
quest_t rpg_init_quest(game_t *game);
quest_board_t *rpg_quest_board_setup(quest_board_t *board, game_t *game);
void rpg_quest_board_update(scene_t *scene);
quest_board_t *rpg_quest_board_update_text(quest_board_t *board,
scene_t *scene);
void rpg_quest_load_from_save(quest_t *quest);
step_t *get_quest_actual_step(quest_t *quest);
bool rpg_quest_board_update_pos(game_object_t *object,
scene_t *scene);

#endif /* !QUEST_HANDLER_H_ */
