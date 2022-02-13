/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_player_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "components/get_from_config.h"
#include "village/village_player.h"
#include "player.h"
#include "stdlib.h"

static void get_anim_from_frames(game_object_t *object, json_object_t *js)
{
    object->anim[PLAYER_DOWN].frames_key = \
    (sfIntRect **)get_frame_keys_from_conf(js, "frame_keys_down");
    object->anim[PLAYER_UP].frames_key = \
    (sfIntRect **)get_frame_keys_from_conf(js, "frame_keys_up");
    object->anim[PLAYER_LEFT].frames_key = \
    (sfIntRect **)get_frame_keys_from_conf(js, "frame_keys_left");
    object->anim[PLAYER_RIGHT].frames_key = \
    (sfIntRect **)get_frame_keys_from_conf(js, "frame_keys_right");
}

static bool player_init_anim(game_object_t *object, json_object_t *js)
{
    object->anim = malloc(sizeof(anim_t) * 5);
    if (object->anim == NULL) {
        return (false);
    }
    for (int i = 0; i != 5; i++)
        object->anim[i] = (anim_t) {NULL, NULL, false, true, 0, 0};
    get_anim_from_frames(object, js);
    for (int i = 0; i != 4; i++)
        if (object->anim[i].frames_key == NULL)
            return (false);
    return (true);
}

game_object_t *rpg_create_player_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_str_from_conf(js, "texture_path");
    game_object_t *object = NULL;
    sfVector2f pos = {0, 0};

    if (path == NULL || !get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object = create_game_object(last, path, pos, PLAYER);
    if (object == NULL || !player_init_anim(object, js)) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    object->move = (sfVector2f) {0, 0};
    object->state = PLAYER_DOWN;
    object->extend = game->player;
    object->free_extend = &player_save;
    object->z_index = object->pos.y / 48;
    update_game_object_frame(object);
    object->update = &update_player;
    return (object);
}