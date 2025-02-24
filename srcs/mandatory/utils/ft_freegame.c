/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freegame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:45 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/24 14:51:22 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	ft_freegame(t_data *app)
{
	int	i;

	if (app->map)
	{
		i = -1;
		while (app->map[++i])
			free(app->map[i]);
		free(app->map);
	}
	if (app->map_arg)
		free(app->map_arg);
	ft_freeitems(app);
	mlx_destroy_window(app->mlx, app->win_game);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	free(app);
	ft_putstr_fd("Come again!\n", 1);
	exit(0);
	return (0);
}
