#ifndef CHECKERS_H
#   define CHECKERS_H

#include "../so_long.h"

void	check_exit(char **map);
void    check_snake(char  **map);
char	**check_map(char *argv);
void	return_error(char	***map);

#endif