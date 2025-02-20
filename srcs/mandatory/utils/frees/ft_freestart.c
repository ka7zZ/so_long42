/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestart_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:11:57 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/20 17:16:41 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"
# include "../../includes/so_long_bonus.h"

int	ft_freestart(t_data *app)
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
	if (app->img_start)
		mlx_destroy_image(app->mlx, app->img_start);
	if (app->win_start)
		mlx_destroy_window(app->mlx, app->win_start);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	free(app);
	exit(0);
	return (0);
}
