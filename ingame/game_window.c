/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:29:07 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/05 14:41:55 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	init_anime(t_data *app)
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

static int	init_paths(t_data *app)
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

int	game_window(t_data *app)
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
		free_start(app);
	init_anime(app);
	init_paths(app);
	deploy_immutable(app);
	deploy_items(app);
	hooks(app);
	return (0);
}
