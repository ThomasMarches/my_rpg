/*
** EPITECH PROJECT, 2020
** Runner
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics.h>

typedef struct game_object game_object_t;
typedef struct scene scene_t;
typedef struct game game_t;

typedef enum {
    SELECTED,
    UNSELECTED
} button_state;

////////////////////////////////////////////////////////////
/// \brief Initialize a game_object that is a button
///
/// Create a animated object with a selected and unselected state
///
/// \param struct game_object last object of the list
/// \param struct char *path for the texture
/// \param sfVector2f position of the button
///
/// \return struct game_object object the created button
////////////////////////////////////////////////////////////
game_object_t *create_text_button(game_object_t *last, char *path, \
sfVector2f pos);

////////////////////////////////////////////////////////////
/// \brief Initialize a game_object that is a button
///
/// Create a animated object with a single animation used on appearition and
/// disparition
///
/// \param struct game_object last object of the list
/// \param struct char *path for the texture
/// \param sfVector2f position of the button
/// \param sfIntRect **frames_key of the animation
///
/// \return struct game_object the created
////////////////////////////////////////////////////////////
game_object_t *create_button(game_object_t *last, char *path, sfVector2f pos, \
sfIntRect **frame_keys);

#endif /* !MENU_H_ */
