/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gw_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:29:07 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/21 14:42:32 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static int	ft_initgif(t_data *app)
{
	app->anime.enemy0 = "../../../assets/xpm/enemy0.xpm";
	app->anime.enemy1 = "../../../xpm/enemy1.xpm";
	app->anime.enemy2 = "../../../xpm/enemy2.xpm";
	app->anime.enemy3 = "../../../xpm/enemy3.xpm";
	app->anime.enemy4 = "../../../xpm/enemy4.xpm";
	app->anime.gate0 = "../../../xpm/gate0.xpm";
	app->anime.gate1 = "../../../xpm/gate1.xpm";
	app->anime.gate2 = "../../../xpm/gate2.xpm";
	app->anime.gate3 = "../../../xpm/gate3.xpm";
	app->anime.gate4 = "../../../xpm/gate4.xpm";
	app->anime.gate5 = "../../../xpm/gate5.xpm";
	return (0);
}

static int	ft_initpath(t_data *app)
{
	app->path.corner = "../../../xpm/corner.xpm";
	app->path.hor_left = "../../../xpm/hor_left.xpm";
	app->path.hor_wall = "../../../xpm/hor_wall.xpm";
	app->path.hor_right = "../../../xpm/hor_right.xpm";
	app->path.ver_up = "../../../xpm/ver_up.xpm";
	app->path.ver_down = "../../../xpm/ver_down.xpm";
	app->path.ver_wall = "../../../xpm/ver_wall.xpm";
	app->path.bg = "../../../xpm/background.xpm";
	app->path.egg = "../../../xpm/egg.xpm";
	app->path.apple = "../../../xpm/food_apple.xpm";
	app->path.enemy = "../../../xpm/enemy0.xpm";
	app->path.snake_ghead = "../../../xpm/snake_ghead.xpm";
	app->path.snake_gdhead = "../../../xpm/snake_gdhead.xpm";
	app->path.snake_gbody = "../../../xpm/snake_gbody.xpm";
	app->path.snake_yhead = "../../../xpm/snake_yhead.xpm";
	app->path.snake_ydhead = "../../../xpm/snake_ydhead.xpm";
	app->path.snake_ybody = "../../../xpm/snake_ybody.xpm";
	app->path.black = "../../../xpm/black.xpm";
	return (0);
}

int	ft_gw(t_data *app)
{
	int	x;
	int	y;

	if (app->img_start)
	{
		mlx_destroy_image(app->mlx, app->img_start);
		app->img_start = NULL;
	}
	if (app->win_start)
	{
		mlx_destroy_window(app->mlx, app->win_start);
		app->win_start = NULL;
	}
	x = app->xlen_win;
	y = app->ylen_win + IMG;
	app->win_game = mlx_new_window(app->mlx, x, y, "Maze munch");
	if (!app->win_game)
		ft_freestart(app);
	ft_initgif(app);
	ft_initpath(app);
	ft_immutable(app);
	ft_items(app);
	ft_hooks(app);
	return (0);
}
