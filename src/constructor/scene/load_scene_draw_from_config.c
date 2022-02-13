/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_scene_draw_from_config
*/

#include "my_game.h"
#include "my_json.h"
#include "my_rpg.h"
#include "components/scene/scene_constructor.h"
#include "components/scene/draw_scene_fp.h"

void load_scene_draw_from_config(json_object_t *js, scene_t *scene)
{
    json_value_t *value = json_get_element_by_key(js, "draw_id");
    int index = 0;

    if (!value || value->value_type != INT)
        return;
    index = *((int *) value->value);
    if (index < 0 || index >= MAX_DRAW_SCENE_ID)
        return;
    scene->draw_scene = DRAW_SCENE_FP[index];
}