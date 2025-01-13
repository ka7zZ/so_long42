/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:49 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 15:21:50 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

void	check_wall(t_data *app, int new_x, int new_y)
{
	t_list	*item;
	t_wseg	*ptr;
	int		i;

	i = 0;
	if (!new_x || !new_y)
		i = 1;
	if (new_x == app->xgw - IMAGE || new_y == app->ygw - IMAGE)
		i = 1;
	item = app->items.wseg;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == new_x && ptr->y == new_y)
			i = 1;
		item = item->next;
	}
	if (i)
	{
		ft_printf("The bricks aren't digestives!\n");
		free_game(app);
	}
}
