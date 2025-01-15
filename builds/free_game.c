/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:45 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/14 18:37:19 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

int	free_game(t_data *app)
{
	int i;

	if (app->map)
	{
		i = -1;
		while(app->map[++i])
			free(app->map[i]);
		free(app->map);
	}
	if (app->map_arg)
		free(app->map_arg);
	if (app->items.black)
		mlx_destroy_image(app->mlx, app->items.black);
	free_items(app);
	if (app->map_arg)
		free(app->map_arg);
	mlx_destroy_window(app->mlx, app->win_game);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	free(app);
	ft_printf("Successfully exit!\n");
	exit(0);
	return (0);
}
