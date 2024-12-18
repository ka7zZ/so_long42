#ifndef CHECKERS_H
#   define CHECKERS_H

#include "../so_long.h"
#   define BUFFER_SZ 1024

int     checker(t_data *app, char *argv);
void	check_map(t_data *app, char *argv);
void	return_error(t_data *app);
void    free_app(t_data *app);

#endif