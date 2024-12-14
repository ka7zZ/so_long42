#ifndef ADDONS_H
#   define ADDONS_H

#include "../mapping.h"

int add_enemy(t_data *app, Map_construct *map);
int add_food(t_data *app, Map_construct *map);
int add_gate(t_data *app, Map_construct *map);
int add_snake(t_data *app, Map_construct *map);
int add_walls(t_data *app, Map_construct *map);

#endif