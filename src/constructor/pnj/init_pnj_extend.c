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
#include "my.h"
#include <stdlib.h>

static const char *background_path = "templates/pnj_button_bg.jpg";

static dialog_t *create_dialog_from_conf(json_object_t *js, dialog_t *next, \
game_t *game, pnj_t *pnj)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));

    if (dialog == NULL)
        return (NULL);
    dialog->next = next;
    dialog->dialog_step = 0;
    if (next != NULL)
        dialog->dialog_step = next->dialog_step + 1;
    pnj->number_of_step = dialog->dialog_step;
    if (!get_int_from_conf(js, (int *) &dialog->dialog_statue, "type") ||
    !get_int_from_conf(js, &dialog->speaker, "speaker")) {
        free(dialog);
        return (NULL);
    }
    dialog->text = my_strdup(get_str_from_conf(js, "message"));
    return (dialog);
}

static dialog_t *rpg_pnj_init_dialog(pnj_t *pnj, json_object_t *js, \
game_t *game)
{
    json_value_t *value = NULL;
    json_array_t *array = NULL;
    dialog_t *list = NULL;
    dialog_t *tmp = NULL;

    value = json_get_element_by_key(js, "dialog");
    if (!value || value->value_type != ARRAY)
        return (NULL);
    array = value->value;
    for (int i = 0; array->array[i]; i++) {
        if (array->array[i]->value_type != OBJECT)
            continue;
        value = json_get_element_by_key(array->array[i]->value, "type");
        if (value && value->value_type == INT) {
            tmp = create_dialog_from_conf(array->array[i]->value, list, \
            game, pnj);
            list = (tmp) ? tmp : list;
        }
    }
    return (list);
}

static bool rpg_pnj_init_extend(json_object_t *js, pnj_t *pnj,
json_object_t **pnj_js)
{
    pnj->dialog_text = NULL;
    pnj->dialog_step = 0;
    pnj->draw_text = 0;
    pnj->json_path = my_strdup(get_str_from_conf(js, "json_path"));
    *pnj_js = json_create_from_file(pnj->json_path);
    pnj->name = my_strdup(get_str_from_conf(*pnj_js, "name"));
    if (!get_int_from_conf(*pnj_js, (int *) &pnj->pnj_id, "id") || \
    !get_int_from_conf(*pnj_js, (int *) &pnj->pnj_type, "type"))
        return (true);
    if (pnj->pnj_type == QUEST_PNJ && !get_int_from_conf(*pnj_js, (int *) \
    &pnj->quest_id, "quest"))
        return (true);
    return (false);
}

static pnj_t *rpg_pnj_init_dialog_background(pnj_t *pnj)
{
    sfVector2f pos = {0, 880};

    if (pnj == NULL)
        return (NULL);
    pnj->background = create_game_object(NULL, (char *) background_path, \
    pos, DECOR);
    if (pnj->background == NULL)
        return (NULL);
    pnj->background->draw = NULL;
    return (pnj);
}

pnj_t *rpg_pnj_init_extend_from_conf(game_object_t *object,
json_object_t *js, game_t *game, scene_t *scene)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));
    json_object_t *pnj_js = NULL;

    if (pnj == NULL)
        return (NULL);
    if (rpg_pnj_init_extend(js, pnj, &pnj_js))
        return (NULL);
    pnj->dialog = rpg_pnj_init_dialog(pnj, pnj_js, game);
    pnj = rpg_pnj_init_dialog_background(pnj);
    if (pnj == NULL || pnj->dialog == NULL)
        return (NULL);
    json_object_destroy(pnj_js);
    return (pnj);
}