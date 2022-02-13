/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json_create_from_file
*/

#include "my_json.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

json_object_t *json_create_from_string(char *buff)
{
    json_object_t *js = json_object_create();

    if (!buff || !js) {
        json_object_destroy(js);
        return (NULL);
    }
    js->key = my_strdup("root");
    if (json_parse_buff(buff, js) == -1) {
        json_object_destroy(js);
        return (NULL);
    }
    return (js);
}

json_object_t *json_create_from_fd(int fd)
{
    json_object_t *js = NULL;
    char *buff = NULL;

    if (fd < 0)
        return (NULL);
    buff = json_get_buff(fd);
    if (!buff)
        return (NULL);
    js = json_create_from_string(buff);
    free(buff);
    return (js);
}

json_object_t *json_create_from_file(char *path)
{
    int fd = open(path, O_RDONLY);
    json_object_t *js = NULL;

    if (fd < 0)
        return (NULL);
    js = json_create_from_fd(fd);
    close(fd);
    return (js);
}