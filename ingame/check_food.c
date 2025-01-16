/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_food.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:04 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/16 16:11:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

int	check_food(t_data *app, int x, int y)
{
	t_list	*item; // food list pointer
	t_list	*buf;  // next food list pointer
	t_list	*prev; // previous food list pointer
	t_food	*ptr;  // food pointer

	item = app->items.food;
	prev = NULL;
	while (item)
	{
		buf = item->next;
		ptr = item->content;
		if (ptr && ptr->x == x && ptr->y == y)
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
