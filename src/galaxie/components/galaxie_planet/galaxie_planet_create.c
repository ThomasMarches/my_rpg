/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** galaxie_planet_create
*/

#include "galaxie/galaxie_planet.h"
#include "components/get_from_config.h"
#include "my.h"
#include <stdlib.h>

static bool galaxie_planet_init_anim(game_object_t *object, json_object_t *js)
{
    object->anim = malloc(sizeof(anim_t) * 2);
    if (object->anim == NULL) {
        return (false);
    }
    object->anim[1] = (anim_t) {NULL, NULL, false, true, 0, 0};
    object->anim[0] = (anim_t) {NULL, NULL, false, true, 0, 0};
    object->anim[0].loop = true;
    object->anim[0].frames_key = get_frame_keys_from_conf(js, "frame_keys");
    if (object->anim[0].frames_key == NULL)
        return (false);
    return (true);
}

game_object_t *galaxie_planet_create_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_str_from_conf(js, "texture_path");
    sfVector2f pos = {0, 0};
    game_object_t *object = NULL;

    if (path == NULL || !get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object = create_game_object(last, path, pos, PLANET);
    if (object == NULL || !galaxie_planet_init_anim(object, js)) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    object->update = &galaxie_planet_update;
    object->extend = my_strdup(get_str_from_conf(js, "config"));
    object->free_extend = &my_free;
    return (object);
}