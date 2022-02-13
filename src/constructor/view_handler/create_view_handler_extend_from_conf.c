/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_view_handler_extend_from_conf
*/

#include "components/view_handler/view_handler.h"
#include "components/get_from_config.h"
#include <stdlib.h>

view_handler_t *create_view_handler_extend_from_conf(json_object_t *js)
{
    view_handler_t *view = NULL;
    sfIntRect view_port = {0, 0, 0, 0};
    sfVector2f angle = {0, 0};
    sfVector2f size = {0, 0};

    if (!get_vector2f_from_conf(js, &size, "size") ||
    !get_intrect_from_conf(js, &view_port, "view_port"))
        return (NULL);
    view = malloc(sizeof(view_handler_t));
    if (view == NULL)
        return (NULL);
    view->size = size;
    view->view_port = (sfFloatRect) {view_port.left, view_port.top,
    view_port.width, view_port.height};
    view->angle = 0.0;
    if (get_vector2f_from_conf(js, &angle, "angle"))
        view->angle = angle.x / angle.y;
    return (view);
}