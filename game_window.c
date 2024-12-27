/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:18 by aghergut          #+#    #+#             */
/*   Updated: 2024/12/27 17:12:46 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"



void	game_window(t_data *app)
{
	int	i;

	i = 0;
	while(app->map[i] != NULL)
		i++;
	app->xw2 = (ft_strlen(app->map[i - 1])) * BLOCK;
	app->yw2 = (i - 1) * BLOCK;
	app->win2 = mlx_new_window(app->mlx, app->xw2, app->yw2, "The journey");
	if (!app->win2)
		destroy_game(app);
	deploy_immutable(app);
	deploy_items(app);
}
