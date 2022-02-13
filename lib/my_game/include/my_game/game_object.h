/*
** EPITECH PROJECT, 2019
** bootstap_runner
** File description:
** game_object
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

typedef struct game game_t;
typedef struct scene scene_t;
typedef struct anim anim_t;

////////////////////////////////////////////////////////////
/// \brief Struct used for an animation of sprite.
////////////////////////////////////////////////////////////
typedef struct anim
{
    sfIntRect **frames_key;      /**< 2D Array of rect in a sprite_sheet*/
    sfSoundBuffer *sound_buffer; /**< Sound of the animation*/
    bool sound_loop;             /**< Bool to determine if the sound as to be looped*/
    bool loop;                   /**< Bool to determine if the animation as to be looped*/
    int frame_id;                /**< Id of the actual frame*/
    int restart_id;              /**< Resart id if the animation loop*/
} anim_t;

typedef enum
{
    BUTTON,
    TEXT_BUTTON,
    SOUND_BAR,
    SOUND_INDICATOR,
    DECOR,
    EFFECT,
    INFO,
    SHOP,
    ENNEMY,
    PNJ,
    SPACESHIP,
    TEXT_HANDLER,
    PLAYER,
    GALAXIE_BACKGROUND,
    PLANET,
    GALAXIE_HUD,
    QUEST_BOARD,
    ATTACK_BUTTON,
    REPAIR_BUTTON,
    DODGE_BUTTON,
    INVENTORY,
    FIGHT_HANDLER,
    MUSIC,
    TILE_MAP,
    CURSOR,
    DIALOG_BUTTON,
} object_type;

////////////////////////////////////////////////////////////
/// \brief Structure representating an object in the game. Used in linked list so it has a pointer to the next node;
////////////////////////////////////////////////////////////
typedef struct game_object
{
    sfTexture *texture;                                   /**< Texture of the object*/
    sfSprite *sprite;                                     /**< Sprite of the object*/
    sfColor sprite_color;                                 /**< Color of the sprite used from fade in/out*/
    sfSound *sound_effect;                                /**< Sound player*/
    sfVector2f pos;                                       /**< Vector of the position of the object*/
    sfVector2f last_pos;                                  /**< Vector of the previous position of the object after a move*/
    int z_index;                                          /**< Index used to display order in scene*/
    sfIntRect box;                                        /**< Box of the object*/
    sfVector2f move;                                      /**< Vector of the move of the object*/
    anim_t *anim;                                         /**< Table of animations for the object*/
    int state;                                            /**< State of the object*/
    object_type type;                                     /**< Type of the object*/
    sfClock *delta_t;                                     /**< Local clock of the object*/
    bool (*update)(struct game_object *, struct scene *); /**< Update function of the object*/
    bool (*callback)(struct game_object *, void *);       /**< Callback function of the object*/
    void (*draw)(sfRenderWindow *, struct game_object *); /**< Draw function of the object*/
    struct game_object *next;                             /**< Next object in the list*/
    void *extend;                                         /**< extend other attributes*/
    void (*free_extend)(void *);
} game_object_t;

////////////////////////////////////////////////////////////
/// \brief Initialize game_object frame
///
/// Initialize game_object frame to the first frame of the
/// frames keys of his actual state
///
/// \param struct game_object object to initialize
////////////////////////////////////////////////////////////
void init_game_object_frame(struct game_object *object);

////////////////////////////////////////////////////////////
/// \brief Update game_object frame
///
/// Update game_object frame to the next frame in the
/// frames keys of his actual state and his is already
/// at the last depending on the value of the loop bool
/// it will start from start or won't change the actual
/// frame
///
/// \param struct game_object object to update
////////////////////////////////////////////////////////////
void update_game_object_frame(struct game_object *object);

////////////////////////////////////////////////////////////
/// \brief Update game_object frame
///
/// Update game_object frame to the previous frame in the
/// frames keys of his actual
/// state and his is already at the first depending on the
/// value of the loop bool it will stop
///
/// \param struct game_object object to update
////////////////////////////////////////////////////////////
void update_game_object_frame_reversed(struct game_object *object);

////////////////////////////////////////////////////////////
/// \brief Update game_object state
///
/// Change game_object state and update his frame keys
///
/// \param struct game_object object to update
/// \param int state the new state of the object
////////////////////////////////////////////////////////////
void update_game_object_state(struct game_object *object, int state);

////////////////////////////////////////////////////////////
/// \brief Create a game_object
///
/// Create and initialize a gameobject with a sprite, a
/// texture, a position and a type.
///
/// \param game_object_t last_object of the linked list
/// \param string path of the texture of the object
/// \param vector pos of the sprite
/// \param object_type type of the game_object
///
/// \return struct game_object *object
////////////////////////////////////////////////////////////
struct game_object *create_game_object(struct game_object *last, char *path, \
                                    sfVector2f pos, object_type type);

////////////////////////////////////////////////////////////
/// \brief Initialize a game_object
///
/// Simply make pointeur equal to NULL and initialize
/// value to zero
///
/// \param struct game_object object to initialize
////////////////////////////////////////////////////////////
void init_game_object(game_object_t *object);

////////////////////////////////////////////////////////////
/// \brief Move a game_object
///
/// Move a game object with his move vector
///
/// \param struct game_object object to move
////////////////////////////////////////////////////////////
void move_object(game_object_t *object);

////////////////////////////////////////////////////////////
/// \brief Draw a list of game_object
///
/// Parse the list and draw each object
///
/// \param struct game_object head of the list of objects
/// \param sfRenderWindow *window window from CSFML used for display
/// \param int z_index_max max deepth of z index
////////////////////////////////////////////////////////////
void draw_objects(game_object_t *object, sfRenderWindow *window, int z_index_max);

////////////////////////////////////////////////////////////
/// \brief Update a list of game_object
///
/// Parse the list and call the function update of each object if it's not NULL
///
/// \param struct scene scene containing the head of object list, needed in case of destroy of the head
/// \param struct game_object head of the list of objects
/// \param struct game game structure given as argument of function update
////////////////////////////////////////////////////////////
void update_objects(scene_t *scene, game_object_t *object, game_t *game);

////////////////////////////////////////////////////////////
/// \brief Destroy a list of game_object
///
/// Destroy a list of game object and for each free all his var
///
/// \param struct scene scene scene who contain the list of objects to be destroyed
////////////////////////////////////////////////////////////
void destroy_object_list(scene_t *scene);

////////////////////////////////////////////////////////////
/// \brief Destroy a game_object
///
/// Destroy a game object and free all his var
///
/// \param struct scene scene who the object is destroy, need in case of destroy of the head
/// \param struct game_object object to destroy
////////////////////////////////////////////////////////////
void destroy_game_object(scene_t *scene, game_object_t *object);

////////////////////////////////////////////////////////////
/// \brief Initialize an appearing game_object
///
/// Initialize an appearing game_object with alpha as 0 and update function as \ref update_appearing_object
///
/// \param struct game_object last object of the list
////////////////////////////////////////////////////////////
void init_appearing_object(game_object_t *last);

////////////////////////////////////////////////////////////
/// \brief Update an appearing game_object
///
/// Increase the alpha of the object until it rech 255
///
/// \param struct game_object object to update
/// \param struct scene scene structure given as argument of update function
////////////////////////////////////////////////////////////
bool update_appearing_object(game_object_t *object, scene_t *);

////////////////////////////////////////////////////////////
/// \brief Update a disappearing game_object
///
/// Decrease the alpha of the object until it reach 0
///
/// \param struct game_object object to update
////////////////////////////////////////////////////////////
void update_disappearing_object(game_object_t *object);

////////////////////////////////////////////////////////////
/// \brief Initialize an animated game_object
///
/// Initialize an animated object with only one animation and state
///
/// \param struct game_object last object of the list
/// \param char *path of the texture
/// \param sfVector2f position of the sprite
/// \param sfIntRet **frame_keys of the animation
////////////////////////////////////////////////////////////
game_object_t *create_animated_object(game_object_t *last, char *, sfVector2f pos,
                                    sfIntRect **frame_keys);


void draw_object(sfRenderWindow *, game_object_t *);
void draw_text(sfRenderWindow *, game_object_t *);

#endif /* !GAME_OBJECT_H_ */
