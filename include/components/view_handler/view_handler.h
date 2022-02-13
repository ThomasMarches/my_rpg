/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** view_handler
*/

#ifndef VIEW_HANDLER_H_
#define VIEW_HANDLER_H_

#include "my_game.h"
#include "my_json.h"

typedef struct {
    sfFloatRect view_port;
    float angle;
    sfVector2f size;
} view_handler_t;

bool view_handler_update(game_object_t *object, scene_t *scene);
view_handler_t *create_view_handler_extend_from_conf(json_object_t *js);

#endif /* !VIEW_HANDLER_H_ */
