/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:58 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/16 17:41:03 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

void	check_gate(t_data *app, int x, int y)
{
	t_list	*food;

	food = app->items.food;
	if (!food)
	{
        change_skin(app);
		show_exit(app);
        app->items.finish = 1;
        app->s_type = 'y';
	}
	if (x == app->items.xpos_gate &&\
        y == app->items.ypos_gate &&\
		app->items.finish == 1)
	{
		ft_printf("You've reached the exit gate!\n");
		free_game(app);
	}
}
