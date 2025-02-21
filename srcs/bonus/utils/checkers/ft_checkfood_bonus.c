/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfood_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:04 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/21 11:47:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long.h"

int	ft_checkfood(t_data *app, int x, int y)
{
	t_list	*item;
	t_list	*buf;
	t_list	*prev;
	t_seg	*ptr;

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
