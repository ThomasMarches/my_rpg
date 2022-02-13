/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** test_indicator
*/

#include <criterion/criterion.h>
#include "my_game.h"
#include "my_json.h"
#include "components/constructors.h"

Test(sound_indicator, indicator)
{
    json_object_t *js = json_create_from_file(
    "tests/constructors/sound_indicator/valid.json");
    game_object_t *object = CONSTRUCTORS[SOUND_INDICATOR_CONSTRUCTOR](NULL,
    js, NULL, NULL);

    cr_assert_neq(js, NULL);
    cr_assert_neq(object, NULL);
    destroy_game_object(NULL, object);
    json_object_destroy(js);
}