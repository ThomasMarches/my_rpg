/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_bar_from_conf
*/

#include "my_game.h"
#include "my_json.h"
#include "options_menu/sound_bar.h"
#include "components/get_from_config.h"
#include <stdlib.h>

static bool rpg_options_init_sound_bar(game_object_t *object, sfIntRect box)
{
    object->state = UNSELECTED;
    object->callback = &rpg_options_sound_bar_callback;
    object->update = &rpg_options_sound_bar_update;
    object->box = box;
    init_appearing_object(object);
    return (false);
}

game_object_t *rpg_options_create_sound_bar_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_str_from_conf(js, "texture_path");
    sfVector2f pos = {0, 0};
    sfIntRect box = {0, 0, 0, 0};
    game_object_t *object = NULL;

    if (path == NULL || !get_vector2f_from_conf(js, &pos, "pos") ||
    !get_intrect_from_conf(js, &box, "box"))
        return (NULL);
    object = create_game_object(last, path, pos, SOUND_INDICATOR);
    if (object == NULL)
        return (NULL);
    rpg_options_init_sound_bar(object, box);
    if (!rpg_options_sound_bar_create_extend_from_conf(object, js)) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    object->free_extend = &free;
    return (object);
}