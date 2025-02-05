/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:18 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/05 15:14:44 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_body(t_data *app, int x, int y)
{
	t_list	*ptr;
	t_seg	*buf;
	int		snake_nodes;

	snake_nodes = 1;
	ptr = app->snake;
	while (ptr)
	{
		buf = ptr->content;
		if (buf->x == x && buf->y == y)
		{
			if (snake_nodes == 2 || snake_nodes == 3)
				return (2);
			if (snake_nodes > 2)
			{
				dead_head(app, app->s_type);
				ft_putstr_fd("You've eaten yourself!\n", 1);
				return (0);
			}
		}
		snake_nodes++;
		ptr = ptr->next;
	}
	return (1);
}
