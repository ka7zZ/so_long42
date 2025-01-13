/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_food.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:04 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 15:22:05 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

int	check_food(t_data *app, int new_x, int new_y)
{
	t_list	*item;
	t_list	*buf;
	t_list	*prev;
	t_food	*ptr;

	item = app->items.food;
	prev = NULL;
	while (item)
	{
		buf = item->next;
		ptr = item->content;
		if (ptr && ptr->x == new_x && ptr->y == new_y)
		{
			mlx_destroy_image(app->mlx, ptr->img);
			ft_lstdelone(item, free);
			if (prev)
				prev->next = buf;
			else
				app->items.food = buf;
			return (1);
		}
		prev = item;
		item = buf;
	}
	return (0);
}
