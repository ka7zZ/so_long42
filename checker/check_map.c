#include "checker.h"

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

static int	check_wall(t_data *app, int last_row)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (app->map[++i] != NULL)
	{
		j = -1;
		len = ft_strlen(app->map[i]);
		if (ft_strchr(app->map[i], '\n'))
			len -= 2; // -1 for \n, -1 for the last 1. This variable is for comprobation of the else if
		if (app->map[i][++j] != '1')
			return_error(app);
		while (app->map[i][++j] != '\n' && app->map[i][j] != '\0')
		{
			
			if ((i == 0 || i == last_row) && app->map[i][j] != '1')
				return_error(app);
		}
		if (app->map[i][--j] != '1')
			return_error(app);
	}
	return (1);
}

static int	check_format(t_data *app)
{
	int 	i;
	int		len;
	int		test;

	i = -1;
	while (app->map[++i] != NULL)
	{
		if (i == 0)
			len = ft_strlen(app->map[i]);
		else
		{
			test = ft_strlen(app->map[i]);
			if (!ft_strchr(app->map[i], '\n'))
				len -= 1;		// -1 because of the char new line at the end of the string
			if (len != test)
				return_error(app);
		}
	}
	if (test == i)
		return_error(app);
	if (check_wall(app, --i)) // --i for the last row of the map
		return (1);
	return (0);
}

static void	read_map(t_data *app, char *argv)
{
	int		fd;
	int		lines;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error reading the map!\n", 23);
		return_error(app);
	}
	lines = count_lines(argv);
	app->map = malloc((lines + 1) * sizeof(char *));
	if (!app->map)
    {
        close(fd);
        return_error(app);
	}
    i = -1;
	while (++i < lines)
		app->map[i] = get_next_line(fd);
	app->map[i] = '\0';
}

void	check_map(t_data *app, char *argv)
{
	int     i;
	int     j;

    read_map(app, argv);
    if (!app->map)
        return_error(app);
	i = 0;
	while (app->map[i] != NULL)
	{
		j = 0;
		while (app->map[i][j] != '\0' && app->map[i][j] != '\n')
		{
			if (!ft_strchr("01EPC", app->map[i][j]))
				return_error(app);
			j++;                
		}
		i++;
	}
    if (check_format(app))
        return ;
	return_error(app);
}
