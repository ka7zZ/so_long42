#include "checkers.h"
/*ERRORS HANDLED
	1. error if there are more than 1 symbol
	2. error if there is not designed enough space for the snake
*/
void	check_symbol(char **map)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (map[++i] != NULL)
	{
		j = 0;
		while (map[i][++j] != NULL)
		{
			if (map[i][j] == 'P')
				s++;
		}
	}
	if (s != 1)
		return_error(&map);	
}

void	check_space(char **map)
{
	int	i;
	int	j;
	int err;

	i = 0;
	err = 1;
	while (map[++i] != NULL)
	{
		j = 0;
		while (map[i][++j] != NULL)
		{
			if (map[i][j] == 'P' &&\
			map[i][j - 1] == '0' && map[i][j + 1] == '0' )
				err = 0;
			else if (map[i][j] == 'P' &&\	
			map[i + 1][j] == '0' && map[i - 1][j] == '0')
				err = 0;
		}
	}
	printf("err ---> %d\n", err);
	if (err)
		return_error(&map);
}

void    check_snake(char  **map)
{
	check_symbol(map);
	check_space(map);
}
