/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** test_check_box
*/

#include <criterion/criterion.h>
#include "components/decor/decor_constructor.h"

Test(test_check_box, create)
{
    json_object_t *js = json_create_from_file(
    "tests/constructors/check_box/valid.json");

    cr_assert_neq(js, NULL);
    json_object_destroy(js);
}