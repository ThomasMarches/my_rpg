/*
** EPITECH PROJECT, 2020
** parce-json
** File description:
** json
*/

#ifndef JSON_H_
#define JSON_H_

typedef enum {
    NONE,
    BOOLEAN,
    INT,
    FLOAT,
    STRING,
    OBJECT,
    ARRAY
} json_value_type;

typedef struct {
    json_value_type value_type;
    void *value;
} json_value_t;

typedef struct {
    int elem_count;
    json_value_t **array;
} json_array_t;

typedef struct json_object {
    char *key;
    json_value_t value;
    struct json_object *next;
} json_object_t;

json_object_t *json_object_create(void);
json_object_t *json_create_from_string(char *buff);
json_object_t *json_create_from_fd(int fd);
json_object_t *json_create_from_file(char *path);
void json_object_destroy(json_object_t *js);

char *json_get_buff(int fd);
int json_parse_buff(char *buff, json_object_t *js);

json_object_t *json_parse_object(char **buff);

json_array_t *json_array_create(void);
void json_array_add_value(json_array_t *, json_value_t *value);
void json_array_destroy(json_array_t *array);

json_value_t *json_value_create(void);
void json_value_destroy(json_value_t *js);

json_value_t json_parse_get_value(char **buff);
json_array_t *json_parse_array(char **buff);
json_value_t *json_parse_value_array(char **buff);
void json_parse_value_object(char **buff, json_object_t *object);
char *json_parse_get_string(char **buff);
json_value_t json_parse_get_int_value(char **buff);
int json_parse_check_next_chr(char **buff);

json_value_t *json_get_element_by_key(json_object_t *js, char *key);

//minilib
int my_getnbr(char const *str);
char *my_strndup(char *str, int n);
char *my_strdup(char const *src);
int my_strlen(const char *);

#endif /* !JSON_H_ */
