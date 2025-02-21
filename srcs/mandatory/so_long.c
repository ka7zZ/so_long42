/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:40:17 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/21 11:44:28 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	ft_maxscreen(t_data *app)
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

static void	ft_initw1(t_data *app)
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
		ft_putstr_fd("MLX loading error\n", 1);
		return ;
	}
	if (!ft_maxscreen(app))
	{
		ft_putstr_fd("Dimensions error!\n", 1);
		ft_freestart(app);
	}
	app->win_start = mlx_new_window(app->mlx, xpix, ypix, "Maze Munch");
	if (!app->win_start)
		ft_freestart(app);
	app->img_start = mlx_xpm_file_to_image(app->mlx, img_path, &xpix, &ypix);
	if (!app->img_start)
		ft_freestart(app);
	mlx_put_image_to_window(app->mlx, app->win_start, app->img_start, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	*app;	

	if (argc != 2)
		return (ft_putstr_fd("Error\n", 1), 1);
	app = (t_data *)malloc(sizeof(t_data));
	if (!app)
		return (ft_putstr_fd("Memory error\n", 1), 1);
	ft_memset(app, 0, sizeof(t_data));
	app->map_arg = ft_strjoin("./assets/maps/", argv[1]);
	if (!app->map_arg)
		return (0);
	ft_buildmap(app, app->map_arg);
	ft_initw1(app);
	ft_hooks(app);
	mlx_loop(app->mlx);
	free(app);
	return (0);
}
