#include "mapping.h"

static void	wrong_format(char	***map)
{
	free_map(map);
	write(1, "Wrong format of the map!\n", 25);
	exit(EXIT_FAILURE);
}

char	**check_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strchr("01EPC", map[i][j]))
				wrong_format(&map);
			j++;                
		}
		i++;
	}
	return (map);
}
