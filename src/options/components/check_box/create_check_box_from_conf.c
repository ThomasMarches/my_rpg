/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_check_box_from_conf
*/

#include "options_menu/check_box.h"
#include "components/get_from_config.h"
#include <stdlib.h>

static bool rpg_create_check_box_frame_keys(json_object_t *js,
game_object_t *object)
{
    sfIntRect **frame_keys = get_frame_keys_from_conf(js, "frame_keys");
    int i = 0;

    for (; frame_keys[i]; i++);
    if (frame_keys == NULL || i != 2)
        return (false);
    object->anim = malloc(sizeof(anim_t) * 2);
    if (object->anim == NULL)
        return (false);
    object->anim[1] = (anim_t) {NULL, NULL, false, false, 0, 0};
    object->anim[0] = (anim_t) {NULL, NULL, false, false, 0, 0};
    object->anim[0].frames_key = frame_keys;
    return (true);
}

game_object_t *rpg_options_create_check_box_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_str_from_conf(js, "texture_path");
    sfVector2f pos = {0, 0};
    game_object_t *object = NULL;
    sfIntRect box = {0, 0, 0, 0};

    if (path == NULL || !get_vector2f_from_conf(js, &pos, "pos") ||
    !get_intrect_from_conf(js, &box, "box"))
        return (NULL);
    object = create_game_object(last, path, pos, DECOR);
    if (object == NULL || !rpg_create_check_box_frame_keys(js, object)) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    object->state = game->window->style == sfFullscreen;
    object->callback = &rpg_check_box_callback;
    object->update = &rpg_check_box_update;
    sfSprite_setTextureRect(object->sprite,
    *(object->anim[0].frames_key[object->state]));
    object->box = box;
    init_appearing_object(object);
    return (object);
}