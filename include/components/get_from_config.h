/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_from_config
*/

#ifndef GET_FROM_CONFIG_H_
#define GET_FROM_CONFIG_H_

#include "my_game.h"
#include "my_json.h"

bool get_vector2f_from_conf(json_object_t *, sfVector2f *, char *);
bool get_intrect_from_conf(json_object_t *, sfIntRect *, char *);
char *get_str_from_conf(json_object_t *, char *);
bool get_int_from_conf(json_object_t *, int *, char *);
sfIntRect **get_frame_keys_from_conf(json_object_t *, char *);
bool get_color_from_conf(json_object_t *, sfColor *, char *);
bool get_bool_from_conf(json_object_t *js, bool *var, char *key);


#endif /* !GET_FROM_CONFIG_H_ */
