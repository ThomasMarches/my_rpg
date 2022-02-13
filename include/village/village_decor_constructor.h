/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** village_decor_constructor
*/

#ifndef VILLAGE_DECOR_CONSTRUCTOR_H_
#define VILLAGE_DECOR_CONSTRUCTOR_H_

enum {
    GRASS,
    PATH,
    TAVERN, // HIT
    ARMOR, // HIT
    FOREST1, // HIT
    FOREST2, // HIT
    FOREST3, // HIT
    SHIP, // HIT
    TREE, // HIT
    WEAPON, // HIT
    HOUSE, // HIT
    CASCADE, // HIT
    ROCK, // HIT
    PNJ1, // HIT
    PNJ2, // HIT
    MAX_TILE_ID
};

static const char *TILE_PATH[] = {
    "./sprites_village/grass-tile.png",
    "./sprites_village/path.png",
    "./sprites_village/tavern.png",
    "./sprites_village/armor.png",
    "./sprites_village/forest2.png",
    "./sprites_village/forest.png",
    "./sprites_village/forest3.png",
    "./sprites_village/ship.png",
    "./sprites_village/tree.png",
    "./sprites_village/weapon.png",
    "./sprites_village/house.png",
    "./sprites_village/cascade.png",
    "./sprites_village/rock.png"
};

#endif /* !VILLAGE_DECOR_CONSTRUCTOR_H_ */
