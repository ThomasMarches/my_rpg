/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** test_save
*/

#include <criterion/criterion.h>
#include "player.h"

Test(test_save, empty)
{
    player_t *player = player_load_from_save_path("tests/save/empty");

    cr_assert_eq(player, NULL);
}

Test(test_save, create_player)
{
    player_t *player = player_create();

    cr_assert_neq(player, NULL);
    cr_assert_eq(player->item_list, NULL);
    cr_assert_eq(player->money, 0);
    cr_assert_eq(player->planet_conf, NULL);
    cr_assert_eq(player->galaxie_dest.x, 0);
    cr_assert_eq(player->galaxie_dest.y, 0);
}