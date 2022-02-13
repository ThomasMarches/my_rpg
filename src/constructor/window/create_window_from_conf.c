/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_window_from_conf
*/

#include "my_json.h"
#include "my_game.h"
#include "components/get_from_config.h"
#include <stdlib.h>

static void try_load_window_icon_from_conf(json_object_t *js, window_t *window)
{
    if (get_str_from_conf(js, "icon_path"))
        set_window_icon(window->window, get_str_from_conf(js, "icon_path"));
}

window_t *create_window_from_conf(char *path)
{
    json_object_t *js = json_create_from_file(path);
    window_t *window = malloc(sizeof(window_t));

    if (js == NULL)
        return (NULL);
    window->name = my_strdup(get_str_from_conf(js, "name"));
    if (window->name == NULL || !get_int_from_conf(js, &window->width, "width")
    || !get_int_from_conf(js, &window->height, "height") ||
    !get_int_from_conf(js, &window->bits, "bits_per_pixel") ||
    !get_int_from_conf(js, &window->framerate, "framerate")) {
        free(window);
        return (NULL);
    }
    window->window = make_window(window, sfDefaultStyle);
    if (window->window == NULL) {
        free(window);
        return (NULL);
    }
    try_load_window_icon_from_conf(js, window);
    json_object_destroy(js);
    return (window);
}