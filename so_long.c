/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:40:17 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 12:47:10 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	screen_size(t_data *app)
{
	int	max_x;
	int	max_y;

	max_x = 0;
	max_y = 0;
	mlx_get_screen_size(app->mlx, &max_x, &max_y);
	if (app->xlen_win > max_x || app->ylen_win > max_y)
		return (0);
	return (1);
}

static void	init_win1(t_data *app)
{
	int		xpix;
	int		ypix;
	char	*img_path;

	xpix = 1024;
	ypix = 1024;
	img_path = "assets/xpm/begin.xpm";
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		ft_putstr_fd("Error loading mlx\n", 1);
		return ;
	}
	if (!screen_size(app))
	{
		ft_putstr_fd("The map have overflow dimensions!\n", 1);
		free_start(app);
	}
	app->win_start = mlx_new_window(app->mlx, xpix, ypix, "Maze Munch");
	if (!app->win_start)
		free_start(app);
	app->img_start = mlx_xpm_file_to_image(app->mlx, img_path, &xpix, &ypix);
	if (!app->img_start)
		free_start(app);
	mlx_put_image_to_window(app->mlx, app->win_start, app->img_start, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	*app;	

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 1);
		return (1);
	}
	app = (t_data *)malloc(sizeof(t_data));
	if (!app)
	{
		ft_putstr_fd("Error: Memory allocation failed\n", 1);
		return (1);
	}
	ft_memset(app, 0, sizeof(t_data));
	app->map_arg = ft_strjoin("./assets/maps/", argv[1]);
	create_map(app, app->map_arg);
	init_win1(app);
	hooks(app);
	mlx_loop(app->mlx);
	free(app);
	return (0);
}
