/*
** EPITECH PROJECT, 2019
** init_bootstrap
** File description:
** window
*/

#include <SFML/Graphics.h>
#include "my_game/window.h"

sfRenderWindow *make_window(window_t *window, int style)
{
    sfVideoMode mode = {window->width, window->height, window->bits};
    sfRenderWindow *window_render = NULL;
    size_t *count = NULL;

    if (style == sfFullscreen)
        mode = sfVideoMode_getFullscreenModes(count)[0];
    window_render = sfRenderWindow_create(mode, window->name, style, NULL);
    if (window_render == NULL)
        return (NULL);
    sfRenderWindow_setFramerateLimit(window_render, window->framerate);
    window->style = style;
    return (window_render);
}

void set_window_icon(sfRenderWindow *window, char *path)
{
    sfImage *img = sfImage_createFromFile(path);
    sfVector2u size = {0, 0};
    sfUint8 *pixels = NULL;

    if (img == NULL)
        return;
    size = sfImage_getSize(img);
    pixels = (sfUint8 *) sfImage_getPixelsPtr(img);
    sfRenderWindow_setIcon(window, size.x, size.y, pixels);
    sfImage_destroy(img);
}