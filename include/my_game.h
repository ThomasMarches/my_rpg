/*
** EPITECH PROJECT, 2020
** Runner
** File description:
** my_game
*/


#ifndef MY_GAME_H_
#define MY_GAME_H_

#include <SFML/Graphics.h>

#include "my_game/game_object.h"
#include "my_game/scene.h"
#include "my_game/menu.h"
#include "my_game/handle_framerate.h"
#include "my_game/cursor.h"
#include "my_game/window.h"
#include "my_game/text.h"

typedef struct game game_t;

////////////////////////////////////////////////////////////
/// \brief Structure containing global variable of the game
////////////////////////////////////////////////////////////
typedef struct game {
    window_t *window;                                       /**< Struct window, from my_graph lib, used to handle the variable of the window*/
    void *player;                                           /**< Struct game_object reference to the main object of the game*/
}game_t;

#endif /* !MY_GAME_H_ */
