/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** test_json
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_json.h"

Test(my_json, valid)
{
    json_object_t *js = json_create_from_file("./tests/json/valid.json");
    json_value_t *value = NULL;

    cr_assert_neq(js, NULL);
    cr_assert_neq(json_get_element_by_key(js, "test"), NULL);
    cr_assert_eq(json_get_element_by_key(js, "full"), NULL);
    value = json_get_element_by_key(js, "true");
    cr_assert_neq(value, NULL);
    cr_assert_eq(value->value_type, BOOLEAN);
    cr_assert_eq(*((bool *) value->value), true);
    value = json_get_element_by_key(js, "1");
    cr_assert_neq(value, NULL);
    cr_assert_eq(value->value_type, ARRAY);
    json_object_destroy(js);
}

Test(my_json, fd)
{
    int fd = open("./tests/json/valid.json", O_RDONLY);
    int fd2 = open("", O_RDONLY);
    json_object_t *js = NULL;

    if (fd < 0)
        cr_assert_fail();
    js = json_create_from_fd(fd);
    cr_assert_neq(js, NULL);
    json_object_destroy(js);
    js = json_create_from_fd(fd2);
    cr_assert_eq(js, NULL);
}

Test(my_json, invalid)
{
    json_object_t *js = json_create_from_file("./tests/json/invalid.json");

    cr_assert_eq(js, NULL);
}

Test(my_json, empty)
{
    json_object_t *js = json_create_from_file("./tests/json/empty.json");

    cr_assert_eq(js, NULL);
}