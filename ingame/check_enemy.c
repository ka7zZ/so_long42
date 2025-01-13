/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:11 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 15:22:13 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

int	check_enemy(t_data *app, int new_x, int new_y)
{
	t_list	*item;
	t_enemy	*ptr;

	item = app->items.enemies;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == new_x && ptr->y == new_y)
			return (1);
		item = item->next;
	}
	return (0);
}
