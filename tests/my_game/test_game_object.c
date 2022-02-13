/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** test_game_object
*/

#include <criterion/criterion.h>
#include "my_game.h"

Test(my_game, game_object)
{
    game_object_t *object = create_game_object(NULL, "templates/npc.png",
    (sfVector2f) {0, 0}, DECOR);

    cr_assert_neq(object, NULL);
    destroy_game_object(NULL, object);
}

Test(my_game, game_object_special)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    cr_assert_neq(object, NULL);
    init_game_object(object);
    destroy_game_object(NULL, object);
}