/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:01 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/22 16:31:07 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long_bonus.h"

static int	count_lines(char *argv)
{
	int		fd;
	int		count;
	int		bytes;
	int		i;
	char	buffer[1024];

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes = read(fd, buffer, 1024);
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
	return (close(fd), ++count);
}

static int	ft_checkborder(t_data *app, int last_row)
{
	int	i;
	int	j;
	int	inside_length;

	i = -1;
	while (app->map[++i] != NULL)
	{
		j = -1;
		if (app->map[i][++j] != '1')
			ft_errormap(app);
		while (app->map[i][++j] != '\n' && app->map[i][j] != '\0')
		{
			if ((i == 0 || i == last_row) && app->map[i][j] != '1')
				ft_errormap(app);
		}
		if (app->map[i][--j] != '1')
			ft_errormap(app);
	}
	inside_length = ft_strlen(app->map[i - 1]) - 2;
	app->xlen_win = (IMG * 2) + (inside_length * X_BLOCK);
	app->ylen_win = i * IMG;
	return (1);
}

static int	ft_checkformat(t_data *app)
{
	int	i;
	int	len;
	int	test;

	i = -1;
	while (app->map[++i] != NULL)
	{
		if (i == 0)
			len = ft_strlen(app->map[i]);
		else
		{
			test = ft_strlen(app->map[i]);
			if (!ft_strchr(app->map[i], '\n'))
				len -= 1;
			if (len != test)
				ft_errormap(app);
		}
	}
	if (test == i)
		ft_errormap(app);
	if (ft_checkborder(app, --i))
		return (1);
	return (0);
}

static void	ft_readmap(t_data *app, char *argv)
{
	int	fd;
	int	lines;
	int	i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_errormap(app);
	lines = count_lines(argv);
	app->map = malloc((lines + 1) * sizeof(char *));
	if (!app->map)
	{
		close(fd);
		ft_errormap(app);
	}
	i = -1;
	while (++i < lines)
		app->map[i] = get_next_line(fd);
	app->map[i] = NULL;
	close(fd);
}

int	ft_checkmap(t_data *app, char *argv)
{
	int	i;
	int	j;

	ft_readmap(app, argv);
	i = 0;
	if (!app->map)
		ft_errormap(app);
	while (app->map[i] != NULL)
	{
		j = 0;
		while (app->map[i][j] != '\0' && app->map[i][j] != '\n')
		{
			if (!ft_strchr("01EPCI", app->map[i][j]))
				ft_errormap(app);
			j++;
		}
		i++;
	}
	if (ft_checkformat(app))
		return (1);
	ft_errormap(app);
	return (0);
}
