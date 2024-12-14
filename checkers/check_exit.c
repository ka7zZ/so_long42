#include "checkers.h"

void	check_exit(char **map)
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
			if (map[i][j] == 'E')
				s++;
		}
	}
	if (s != 1)
		return_error(&map);	
}