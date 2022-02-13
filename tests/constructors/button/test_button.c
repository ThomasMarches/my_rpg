/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** test_button
*/

#include <criterion/criterion.h>
#include "components/button/button.h"
#include "components/constructors.h"

Test(test_button, valid)
{
    json_object_t *js = json_create_from_file(
    "tests/constructors/button/valiad_animated.json");
    game_object_t *bt = NULL;

    cr_assert_neq(js, NULL);
    bt = CONSTRUCTORS[BUTTON_CONSTRUCTOR](NULL,
    js, NULL, NULL);
    cr_assert_neq(bt, NULL);
    destroy_game_object(NULL, bt);
    json_object_destroy(js);
}