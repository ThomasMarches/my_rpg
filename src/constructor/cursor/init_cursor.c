/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** init_cursor.c
*/

#include "my_game.h"
#include "my_json.h"
#include "components/get_from_config.h"

void rpg_draw_cursor(sfRenderWindow *window, game_object_t *object)
{
    sfVector2f pos = get_mouse_exact_pos(window);
    sfVector2f position;

    position.x = pos.x;
    position.y = pos.y;
    object->pos = position;
    sfSprite_setPosition(object->sprite, position);
    sfRenderWindow_drawSprite(window, object->sprite, NULL);
}

game_object_t *rpg_cursor_create_from_conf(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene)
{
    game_object_t *object = create_game_object(last, get_str_from_conf(js, \
    "texture_path"), (sfVector2f) {0, 0}, CURSOR);

    if (object == NULL)
        return (NULL);
    sfRenderWindow_setMouseCursorVisible(scene->window, sfFalse);
    object->draw = &rpg_draw_cursor;
    object->callback = NULL;
    return (object);
}
