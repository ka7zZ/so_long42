/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:18 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/08 18:45:38 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	start_race(t_list *app)
// {
	
// }

static void	init_paths(t_data *app)
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
	app->path.enemy = "./assets/xpm/enemy.xpm";
	app->path.exit_gate = "./assets/xpm/exit_gate.xpm";
	app->path.start_gate = "./assets/xpm/start_gate.xpm";
	app->path.snake_bdead = "./assets/xpm/snake_bdead.xpm";
	app->path.snake_body = "./assets/xpm/snake_body.xpm";
	app->path.snake_hdead = "./assets/xpm/snake_hdead.xpm";
	app->path.snake_head = "./assets/xpm/snake_head.xpm";
	app->path.black = "./assets/xpm/black.xpm";
}

void	game_window(t_data *app)
{	
	int	i;
	int	map_width;

	i = 0;
	map_width = ft_strlen(app->map[0]) - 1;
	while(app->map[i] != NULL)
		i++;
	app->xgw = ((ft_strlen(app->map[i - 1])) * X_BLOCK) - X_BLOCK;
	app->ygw = (i - 1) * Y_BLOCK;
	app->win_game = mlx_new_window(app->mlx, app->xgw, app->ygw + IMAGE, "Maze munch");
	if (!app->win_game)
		free_start(app);
	init_paths(app);
	deploy_immutable(app);
	deploy_items(app);
	game_hooks(app);
}
