/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_sound_bar
*/

#include "my_game.h"
#include "options_menu/sound_bar.h"

bool rpg_options_sound_bar_update(game_object_t *bar, scene_t *scene)
{
    sfVector2f pos = get_mouse_exact_pos(scene->window);
    rpg_options_sound_bar_t *bar_s = bar->extend;
    int vol = sfListener_getGlobalVolume() / bar_s->volume_unit;
    int bar_width = bar->box.width / bar_s->volume_unit;
    int bar_pos_x = bar_s->default_x;
    sfIntRect rect = {0, 0, bar->box.width, bar->box.height};

    if (bar->state == SELECTED)
        vol = (pos.x - bar_pos_x) / bar_width;
    if (!sfMouse_isButtonPressed(sfMouseLeft))
            bar->state = UNSELECTED;
    if (vol > bar_s->max_volume / bar_s->volume_unit)
        vol = bar_s->max_volume / bar_s->volume_unit;
    else if (vol < bar_s->min_volume)
        vol = bar_s->min_volume;
    rect.width = bar_width * vol;
    sfListener_setGlobalVolume(vol * bar_s->volume_unit);
    sfSprite_setTextureRect(bar->sprite, rect);
    update_appearing_object(bar, scene);
    return (true);
}