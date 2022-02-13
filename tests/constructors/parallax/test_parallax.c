/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** test_parallax
*/

#include <criterion/criterion.h>
#include "components/decor/decor_constructor.h"
#include "components/constructors.h"

Test(test_parallax, create)
{
    json_object_t *js = json_create_from_file(
    "tests/constructors/parallax/valid.json");
    game_object_t *object = CONSTRUCTORS[PARALLAX_CONSTRUCTOR](NULL, js, NULL,
    NULL);

    cr_assert_neq(js, NULL);
    cr_assert_neq(object, NULL);
    destroy_game_object(NULL, object);
    json_object_destroy(js);
}