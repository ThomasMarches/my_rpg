/*
** EPITECH PROJECT, 2020
** Runner
** File description:
** scene
*/

#ifndef SCENE_H_
#define SCENE_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "event.h"

typedef struct game_object game_object_t;
typedef struct game game_t;

////////////////////////////////////////////////////////////
/// \brief Struct scene used for to handle each scene
////////////////////////////////////////////////////////////
typedef struct scene {
    void (*update_scene)(struct scene *, struct game *);                        /**< Function that update this scene*/
    void (*draw_scene)(struct scene *, struct game *, sfRenderWindow *);
    game_object_t *objects_list;                                                /**< List of object of this scene*/
    bind_event_t *binds_list;
    sfColor background_color;                                                   /**< Color of the background of this scene*/
    int z_index_deepth;                                                         /**< Max deepth of z_index for objects display*/
    int display;                                                                /**< The displayed scene used for switch between scene*/
    int joystick_coord_id;                                                      /**< The coord to simulate the mouse for joystick*/
    sfRenderWindow *window;                                                     /**< sfRenderWindow used for display*/
    game_t *game;
} scene_t;

////////////////////////////////////////////////////////////
/// \brief Display a scene
///
/// Clear the window with the background color and then draw each object of the scene
///
/// \param struct scene scene to be displayed
/// \param sfRenderWindow window to display the scene
////////////////////////////////////////////////////////////
void display_scene(scene_t *, sfRenderWindow *);

////////////////////////////////////////////////////////////
/// \brief Destroy a scene
///
/// Destroy the objects of the scene and free the struct
///
/// \param struct scene scene to be destroyed
////////////////////////////////////////////////////////////
void destroy_scene(scene_t *);

////////////////////////////////////////////////////////////
/// \brief Create an empty scene
///
/// Create and initialize a scene with no objects
///
/// \param game_t pointeur to the main struct of the game
///
/// \return struct scene *scene
////////////////////////////////////////////////////////////
scene_t *create_empty_scene(game_t *);

void disappear_scene(scene_t *scene, sfRenderWindow *window, sfClock *clock, \
game_t *game);

void update_scene(scene_t *scene, game_t *game);
bool disappear_scene_objects(scene_t *scene);
scene_t *create_scene_from_file(const char *, game_t *game);
int scene_loop(game_t *, const char *);

#endif /* !SCENE_H_ */
