/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event
*/

#ifndef EVENT_H_
#define EVENT_H_

#include <SFML/Window/Event.h>
#include <SFML/Graphics/RenderWindow.h>

typedef struct game game_t;
typedef struct scene scene_t;

typedef struct bind_event {
    sfEventType id;
    void (*bind)(sfEvent, game_t *, scene_t *, sfRenderWindow *);
    struct bind_event *next;
} bind_event_t;

void bind_event(scene_t *, sfEventType, void (*)(sfEvent, game_t *, scene_t *, sfRenderWindow *));
void destroy_binds_list(bind_event_t *);
void destroy_bind(bind_event_t **, bind_event_t *);
void handle_scene_event(scene_t *scene, game_t *game, sfRenderWindow *window);
void close_scene(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window);
void is_click_on_object(sfEvent event, game_t *game, scene_t *scene, sfRenderWindow *window);
sfVector2f get_mouse_exact_pos(sfRenderWindow *window);

#endif /* !EVENT_H_ */
