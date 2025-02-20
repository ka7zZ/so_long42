/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gw_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:29:07 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/20 17:40:30 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	ft_initgif(t_data *app)
{
	app->anime.enemy0 = "./assets/xpm/enemy0.xpm";
	app->anime.enemy1 = "./assets/xpm/enemy1.xpm";
	app->anime.enemy2 = "./assets/xpm/enemy2.xpm";
	app->anime.enemy3 = "./assets/xpm/enemy3.xpm";
	app->anime.enemy4 = "./assets/xpm/enemy4.xpm";
	app->anime.gate0 = "./assets/xpm/gate0.xpm";
	app->anime.gate1 = "./assets/xpm/gate1.xpm";
	app->anime.gate2 = "./assets/xpm/gate2.xpm";
	app->anime.gate3 = "./assets/xpm/gate3.xpm";
	app->anime.gate4 = "./assets/xpm/gate4.xpm";
	app->anime.gate5 = "./assets/xpm/gate5.xpm";
	return (0);
}

static int	ft_initpath(t_data *app)
{
	app->path.corner = "./assets/xpm/corner.xpm";
	app->path.hor_left = "./assets/xpm/hor_left.xpm";
	app->path.hor_wall = "./assets/xpm/hor_wall.xpm";
	app->path.hor_right = "./assets/xpm/hor_right.xpm";
	app->path.ver_up = "./assets/xpm/ver_up.xpm";
	app->path.ver_down = "./assets/xpm/ver_down.xpm";
	app->path.ver_wall = "./assets/xpm/ver_wall.xpm";
	app->path.bg = "./assets/xpm/background.xpm";
	app->path.egg = "./assets/xpm/egg.xpm";
	app->path.apple = "./assets/xpm/food_apple.xpm";
	app->path.enemy = "./assets/xpm/enemy0.xpm";
	app->path.snake_ghead = "./assets/xpm/snake_ghead.xpm";
	app->path.snake_gdhead = "./assets/xpm/snake_gdhead.xpm";
	app->path.snake_gbody = "./assets/xpm/snake_gbody.xpm";
	app->path.snake_yhead = "./assets/xpm/snake_yhead.xpm";
	app->path.snake_ydhead = "./assets/xpm/snake_ydhead.xpm";
	app->path.snake_ybody = "./assets/xpm/snake_ybody.xpm";
	app->path.black = "./assets/xpm/black.xpm";
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
