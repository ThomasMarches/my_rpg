/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sound_indicator_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "options_menu/sound_indicator.h"
#include "components/get_from_config.h"

game_object_t *rpg_options_create_sound_indicator_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene)
{
    char *path = get_str_from_conf(js, "texture_path");
    sfVector2f pos = {0, 0};
    game_object_t *object = NULL;

    if (path == NULL || !get_vector2f_from_conf(js, &pos, "pos"))
        return (NULL);
    object = create_game_object(last, path, pos, SOUND_INDICATOR);
    if (object == NULL)
        return (NULL);
    init_appearing_object(object);
    object->update = &rpg_options_update_sound_indicator;
    if (!rpg_options_sound_indicator_create_extend_from_conf(object, js)) {
        destroy_game_object(scene, object);
        return (NULL);
    }
    return (object);
}