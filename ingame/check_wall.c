/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:49 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 13:08:52 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_wall(t_data *app, int x, int y)
{
	t_list	*item;
	t_wseg	*ptr;
	int		i;

	i = 0;
	if (!x || !y)
		i = 1;
	if (x == app->xlen_win - IMG || y == app->ylen_win - IMG)
		i = 1;
	item = app->items.wseg;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == x && ptr->y == y)
			i = 1;
		item = item->next;
	}
	if (i)
	{
		dead_head(app, app->s_type);
		ft_printf("The bricks aren't digestives!\n");
	}
	return (i);
}
