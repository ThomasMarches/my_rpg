/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quest_handler
*/

#include "components/quest/quest.h"
#include "my_game.h"
#include "my_json.h"

#ifndef PNJ_H_
#define PNJ_H_

typedef enum {
    GET_QUEST,
    GIVE_BACK_QUEST,
    DOING_QUEST,
    NORMAL_STEP,
} dialog_statue;

typedef enum {
    PNJ_QUEST1,
    PNJ_QUEST2,
    PNJ_QUEST3,
    PNJ_QUEST4,
    PNJ_DIALOG1,
    PNJ_DIALOG2,
    PNJ_DIALOG3,
    PNJ_DIALOG4,
    SECOND_QUEST_PNJ,
    MAX_PNJ_ID
} pnj_id;

typedef enum {
    QUEST_PNJ,
    DIALOG_PNJ,
    SHOP_PNJ
} pnj_type;

typedef struct dialog {
    char *text;
    int speaker;
    dialog_statue dialog_statue;
    int dialog_step;
    struct dialog *next;
} dialog_t;

typedef struct pnj {
    char *json_path;
    char *name;
    int dialog_step;
    quest_id quest_id;
    bool draw_text;
    int number_of_step;
    dialog_statue quest_statue;
    pnj_id pnj_id;
    game_object_t *background;
    pnj_type pnj_type;
    dialog_t *dialog;
    sfText *dialog_text;
} pnj_t;

void free_text(sfText *text);
game_object_t *rpg_pnj_init_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
void rpg_pnj_destroy(void *pt);
pnj_t *rpg_pnj_init_extend_from_conf(game_object_t *object,
json_object_t *js, game_t *game, scene_t *scene);
bool rpg_pnj_callback(game_object_t *object, void *pt);
bool rpg_pnj_button_update(game_object_t *object, scene_t *scene);
bool rpg_pnj_button_callback(game_object_t *object, void *pt);
void rpg_dialog_set_text(pnj_t *pnj, scene_t *scene, dialog_t *dialog);
void rpg_dialog_advance_step(pnj_t *pnj, scene_t *scene, dialog_t *dialog);
bool rpg_pnj_update(game_object_t *object, scene_t *scene);
void rpg_pnj_open_dialog_give_quest(pnj_t *pnj, scene_t *scene);
void rpg_pnj_open_dialog_quest_over(pnj_t *pnj, scene_t *scene);
void rpg_pnj_open_dialog_doing_quest(pnj_t *pnj, scene_t *scene);
void rpg_quest_dialog_advance_step(pnj_t *pnj, scene_t *scene,
dialog_t *dialog);
void rpg_pnj_quest_callback(game_object_t *object, scene_t *scene, pnj_t *pnj);
void rpg_pnj_dialog_callback(game_object_t *object, scene_t *scene, pnj_t *pnj);
game_object_t *rpg_pnj_init_button(game_object_t *last);
void rpg_pnj_button_draw(sfRenderWindow *window, game_object_t *object);
void rpg_draw_pnj(sfRenderWindow *window, game_object_t *object);

#endif /* !PNJ_H_ */
