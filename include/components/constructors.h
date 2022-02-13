/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** constructors
*/

#ifndef CONSTRUCTORS_H_
#define CONSTRUCTORS_H_

#include "my_game.h"
#include "my_json.h"

enum {
    DECOR_CONSTRUCTOR,
    BUTTON_CONSTRUCTOR,
    ANIMATED_BUTTON_CONSTRUCTOR,
    PARALLAX_CONSTRUCTOR,
    SOUND_INDICATOR_CONSTRUCTOR,
    SOUND_BAR_CONSTRUCTOR,
    CHECK_BOX_CONSTRUCTOR,
    TEXT_HANDLER_CONSTRUCTOR,
    GALAXIE_SPACESHIP_CONSTRUCTOR,
    GALAXIE_MINIMAP_CONSTRUCTOR,
    GALAXIE_PLANET_CONSTRUCTOR,
    GALAXIE_HUD_CONSTRUCTOR,
    INVENTORY_CONSTRUCTOR,
    ENNEMY_CONSTRUCTOR,
    SPACESHIP_CONSTRUCTOR,
    FIGHT_HANDLER_CONSTRUCTOR,
    PLAYER_CONSTRUCTOR,
    MUSIC_HANDLER_CONSTRUCTOR,
    VILLAGE_CONSTRUCTOR,
    CURSOR_CONSTRUCTOR,
    QUEST_BOARD_CONSTRUCTOR,
    PNJ_CONSTRUCTOR,
    DIALOG_BUTTON_CONSTRUCTOR,
    CONSTRUCTORS_MAX_ID
};

game_object_t *rpg_create_decor_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_create_button_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_create_animated_button_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_create_parallax_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_options_create_sound_indicator_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_options_create_sound_bar_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_options_create_check_box_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_create_text_handler_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene);
game_object_t *create_view_handler_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene);
game_object_t *create_galaxie_spaceship_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene);
game_object_t *create_galaxie_mini_map(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene);
game_object_t *galaxie_planet_create_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene);
game_object_t *galaxie_hud_create(game_object_t *last, json_object_t *js,
game_t *game, scene_t *scene);
game_object_t *rpg_inventory_create_from_conf(game_object_t *, json_object_t *,
game_t *, scene_t *);
game_object_t *rpg_ennemy_create(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene);
game_object_t *rpg_space_ship_create(game_object_t *last, \
json_object_t *js, game_t *game, scene_t *scene);
game_object_t *rpg_fight_handler_create_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_create_player_from_conf(game_object_t *last,
json_object_t *js, game_t *game, scene_t *scene);
game_object_t *rpg_music_handler_create_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_cursor_create_from_conf(game_object_t *, json_object_t *,
game_t *, scene_t *);
game_object_t *create_village(game_object_t *, json_object_t *,
game_t *, scene_t *);
game_object_t *rpg_quest_board_create_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_pnj_constructor(game_object_t *,
json_object_t *, game_t *, scene_t *);
game_object_t *rpg_pnj_init_button_from_conf(game_object_t *,
json_object_t *, game_t *, scene_t *);

static game_object_t *(*CONSTRUCTORS[])(game_object_t *, json_object_t *,
game_t *, scene_t *) = {
    &rpg_create_decor_from_conf,
    &rpg_create_button_from_conf,
    &rpg_create_animated_button_from_conf,
    &rpg_create_parallax_from_conf,
    &rpg_options_create_sound_indicator_from_conf,
    &rpg_options_create_sound_bar_from_conf,
    &rpg_options_create_check_box_from_conf,
    &rpg_create_text_handler_from_conf,
    &create_galaxie_spaceship_from_conf,
    &create_galaxie_mini_map,
    &galaxie_planet_create_from_conf,
    &galaxie_hud_create,
    &rpg_inventory_create_from_conf,
    &rpg_ennemy_create,
    &rpg_space_ship_create,
    &rpg_fight_handler_create_from_conf,
    &rpg_create_player_from_conf,
    &rpg_music_handler_create_from_conf,
    &create_village,
    &rpg_cursor_create_from_conf,
    &rpg_quest_board_create_from_conf,
    &rpg_pnj_constructor,
    &rpg_pnj_init_button_from_conf
};

#endif /* !CONSTRUCTORS_H_ */
