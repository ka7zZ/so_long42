/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:58 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 15:22:00 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

void	check_gate(t_data *app, int new_x, int new_y)
{
	t_list	*food;

	food = app->items.food;
	if (!food)
	{
		mlx_destroy_image(app->mlx, app->items.start_gate);
		assign_image(app, &(app->items.start_gate), app->path.exit_gate);
		deploy_image(app, app->items.start_gate, app->items.xsg, app->items.ysg);
		if (new_x == app->items.xsg && new_y == app->items.ysg)
		{
			ft_printf("You've reached the exit gate!\n");
			free_game(app);
		}
	}
}
