/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** test_sound_bar
*/

#include <criterion/criterion.h>
#include "my_game.h"
#include "my_json.h"
#include "components/constructors.h"

Test(sound_bard, sound_bar)
{
    json_object_t *js = json_create_from_file(
    "tests/constructors/sound_bar/valid.json");
    game_object_t *object = CONSTRUCTORS[SOUND_BAR_CONSTRUCTOR](NULL,
    js, NULL, NULL);

    cr_assert_neq(js, NULL);
    cr_assert_neq(object, NULL);
    destroy_game_object(NULL, object);
    json_object_destroy(js);
}