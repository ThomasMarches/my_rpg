/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_scene_event_from_config
*/

#include "my_game.h"
#include "my_json.h"
#include "my_rpg.h"
#include "components/scene/event_scene_fp.h"

static void load_scene_event_get_index_and_event_type(json_array_t *array, \
sfVector2i *bind)
{
    if (array->elem_count != 2)
        return;
    for (int i = 0; array->array[i]; i++)
        if (array->array[i]->value_type != INT)
            return;
    bind->x = *((int *) array->array[0]->value);
    bind->y = *((int *) array->array[1]->value);
}

bool load_scene_event_from_config(json_object_t *js, scene_t *scene)
{
    json_value_t *value = json_get_element_by_key(js, "events_ids");
    bool has_leave = false;
    json_array_t *array = NULL;
    sfVector2i bind = {-1, -1};

    if (!value || value->value_type != ARRAY)
        return (false);
    array = value->value;
    for (int i = 0; array->array[i]; i++) {
        if (array->array[i]->value_type != ARRAY)
            continue;
        load_scene_event_get_index_and_event_type(array->array[i]->value, \
        &bind);
        if (bind.x < 0 || bind.x >= MAX_SCENE_EVENT_ID)
            continue;
        else if (bind.x == 0)
            has_leave = true;
        bind_event(scene, bind.y, EVENT_SCENE_FP[bind.x]);
    }
    return (has_leave);
}