#ifndef INGAME_H
#   define INGAME_H

#include "../so_long.h"

int eat(t_data *app, Map_construct *map);
int finish(t_data *app, Map_construct *map);
int move_down(t_data *app, Map_construct *map);
int move_left(t_data *app, Map_construct *map);
int move_right(t_data *app, Map_construct *map);
int move_up(t_data *app, Map_construct *map);
int showdown(t_data *app, Map_construct *map);

#endif