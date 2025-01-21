/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:11 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/20 12:48:36 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

int	check_enemy(t_data *app, int x, int y)
{
	t_list	*item;
	t_seg	*ptr;

	item = app->items.enemies;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == x && ptr->y == y)
			return (1);
		item = item->next;
	}
	return (0);
}
