#include "mapping.h"

static void wrong_format(char	***map)
{
	free_map(map);
	ft_printf("Wrong format of the map!\n");
	exit(EXIT_FAILURE);
}

static int	count_lines(char *argv)
{
	int		fd;
	int		count;
	int		bytes;
	int		i;
	char	buffer[BUFFER_SZ];

	fd = open(argv, O_RDONLY);
	bytes = read(fd, buffer, BUFFER_SZ);
	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	close(fd);
	return (++count);
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
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = '\0';
	return (map);
}

/*NEXT FUNC ERRORS HANDLING:
	1. eroare in cazul in care orice rand nu incepe cu un wall
	2. eroare on cazul in care primul si ultimul rand nu contin numai wall
	3. eroare in cazul in care harta contine pe linia verticala mai mult de un wall
	4. eroare in cazul in care ultimul caracter nu este 1
*/

static int	check_format(char **map, int last_row)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		if (map[i][j] != '1')
			wrong_format(&map);
		len = ft_strlen(map[i]);
		if (ft_strchr(map[i], '\n'))
			len -= 2; // -1 for \n, -1 for the last 1. This variable is for comprobation of the else if
		j++;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			
			if ((i == 0 || i == last_row) && map[i][j] != '1')
				wrong_format(&map);
			else if ((i > 0 == i < last_row) && j < len && map[i][j] == '1')
				wrong_format(&map);
			j++;
		}
		if (map[i][--j] != '1')
			wrong_format(&map);
		i++;
	}
	return (1);
}

char	**check_input(char *argv)
{
	int 	i;
	int		len;
	int		test;
	char    **input;

	input = read_map(argv);
	i = -1;
	while (input[++i] != NULL)
	{
		if (i == 0)
			len = ft_strlen(input[i]);
		else
		{
			test = ft_strlen(input[i]);
			if (!ft_strchr(input[i], '\n'))
				len -= 1;		// -1 because of the char new line at the end of the string
			if (len != test)
				wrong_format(&input);
		}
	}
	if (test == i)
		wrong_format(&input);
	if (check_format(input, --i)) // --i for the last row of the map
		return (input);
	return (0);
}
