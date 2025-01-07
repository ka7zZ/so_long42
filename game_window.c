/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:18 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/07 17:17:48 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static void destroy_images(t_data *app)
{
	mlx_destroy_image(app->mlx, app->game->wall.bg);
	mlx_destroy_image(app->mlx, app->game->wall.corner);
	mlx_destroy_image(app->mlx, app->game->wall.lr_down);
	mlx_destroy_image(app->mlx, app->game->wall.lr_up);
	mlx_destroy_image(app->mlx, app->game->wall.ud_left);
	mlx_destroy_image(app->mlx, app->game->wall.ud_right);
	mlx_destroy_image(app->mlx, app->game->wall.side_hor);
	mlx_destroy_image(app->mlx, app->game->wall.side_ver);
	if (app->game->item.food)
		mlx_destroy_image(app->mlx, app->game->item.food);
	mlx_destroy_image(app->mlx, app->game->item.start_gate);
	if (app->game->item.enemy)
		mlx_destroy_image(app->mlx, app->game->item.exit_gate);
	if (app->game->item.enemy)
	mlx_destroy_image(app->mlx, app->game->item.enemy);
	// mlx_destroy_image(app->mlx, snake->head);
	// while (snake->body->next != NULL)
	// {
	// 	buff = snake->body->next;
	// 	free(snake->body->content);
	// 	snake->body = buff;	
	// }
	// free(snake->body->content);
	// free(snake->body);
}


static int	on_destroy(t_data *app)
{
	int i;

	if (app->map)
	{
		i = -1;
		while(app->map[++i])
			free(app->map[i]);
		free(app->map);
	}
	if (app->game->wall.bg)
		ft_printf("hereeee");
	destroy_images(app);
	exit(0);
}

void	game_hooks(t_data *app)
{
	mlx_hook(app->win, DestroyNotify, NoEventMask, on_destroy, app);
}


void	game_window(t_data *app)
{
	int	i;

	i = 0;
	app->game = (t_map *)malloc(sizeof(t_map));
	if (!app->game)
		free_start(app);
	while(app->map[i] != NULL)
		i++;
	app->xgw = (ft_strlen(app->map[i - 1])) * BLOCK;
	app->ygw = (i - 1) * BLOCK;
	app->win = mlx_new_window(app->mlx, app->xgw, app->ygw, "Maze munch");
	if (!app->win)
		destroy_game(app);
	deploy_immutable(app);
	deploy_items(app);
	game_hooks(app);
}
