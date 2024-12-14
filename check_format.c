#include "checkers.h"
/*ERRORS HANDLED:

	1. error in case every row not starts and ends with a wall
	2. error in case of the first and the last row is not composed only of walls
	3. error in case of the intrusions of walls between of the 1st rows and the last
	4. error if the map is not rectangular
*/

static int	count_lines(char *argv)
{
	int		fd;
	int		count;
	int		bytes;
	int		i;
	char	buffer[BUFFER_SZ];

	fd = open(argv, O_RDONLY);
	if (fd < 0)
        return (0);
	bytes = read(fd, buffer, BUFFER_SZ);
	if (bytes < 0)
		return (close(fd), 0);
	buffer[bytes] = '\0';
	i = 0;
	count = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	close(fd);
	return (++count);
}

static int	check_wall(char **map, int last_row)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		len = ft_strlen(map[i]);
		if (ft_strchr(map[i], '\n'))
			len -= 2; // -1 for \n, -1 for the last 1. This variable is for comprobation of the else if
		if (map[i][++j] != '1')
			return_error(&map);
		while (map[i][++j] != '\n' && map[i][j] != '\0')
		{
			
			if ((i == 0 || i == last_row) && map[i][j] != '1')
				return_error(&map);
			else if ((i > 0 == i < last_row) && j < len && map[i][j] == '1')
				return_error(&map);
		}
		if (map[i][--j] != '1')
			return_error(&map);
	}
	return (1);
}

static int	check_format(char **map)
{
	int 	i;
	int		len;
	int		test;

	i = -1;
	while (map[++i] != NULL)
	{
		if (i == 0)
			len = ft_strlen(map[i]);
		else
		{
			test = ft_strlen(map[i]);
			if (!ft_strchr(map[i], '\n'))
				len -= 1;		// -1 because of the char new line at the end of the string
			if (len != test)
				return_error(&map);
		}
	}
	if (test == i)
		return_error(&map);
	if (check_wall(map, --i)) // --i for the last row of the map
		return (1);
	return (0);
}

static char	**read_map(char *argv)
{
	char	**map;
	int		fd;
	int		lines;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error reading the map!\n", 23);
		exit(EXIT_FAILURE);
	}
	lines = count_lines(argv);
	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (close(fd), NULL);
	i = -1;
	while (++i < lines)
		map[i] = get_next_line(fd);
	map[i] = NULL;
    return (map);
}

char	**check_map(char *argv)
{
    char    **map;
	int     i;
	int     j;

    map = read_map(argv);
    if (!map)
        return_error(&map);
	i = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strchr("01EPC", map[i][j]))
				return_error(&map);
			j++;                
		}
		i++;
	}
    if (check_format(map))
        return (map)
	return (NULL);
}
