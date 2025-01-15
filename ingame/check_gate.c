/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:58 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/15 11:55:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

void	check_gate(t_data *app, int new_x, int new_y)
{
	t_list	*food;

	food = app->items.food;
	if (!food)
	{
		app->items.finish = 1;
		show_exit(app);
		change_skin(app);
		app->s_type = 'y';
	}
	if (new_x == app->items.xgate \
		&& new_y == app->items.ygate \
		&& app->items.finish)
	{
		ft_printf("You've reached the exit gate!\n");
		free_game(app);
	}
}
