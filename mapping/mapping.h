#ifndef MAPPING_H
#   define MAPPING_H

# include "../so_long.h"
# include "addons/addons.h"

# define BUFFER_SZ  1024
int     check_input(char *argv);
void    create_map(t_data *app, Map_construct *map);
void    free_map(char ***map);
#endif