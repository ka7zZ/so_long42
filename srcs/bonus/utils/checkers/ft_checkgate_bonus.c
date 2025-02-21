/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkgate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:58 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/21 11:47:11 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long.h"

static int	ft_show(t_data *app)
{
	t_list		*ptr;
	t_seg		*buf;
	static int	n = 0;
	int			temp;

	if (n == 9)
		n = 8;
	ptr = app->items.gate;
	n++;
	temp = n;
	while (ptr && temp--)
	{
		buf = ptr->content;
		ptr = ptr->next;
	}
	if (buf->img)
		ft_deployimg(app, buf->img, buf->x, buf->y);
	return (0);
}

void	ft_checkgate
(t_data *app, int x, int y)
{
	t_list	*food;

	food = app->items.food;
	if (!food)
	{
		ft_changeskin(app);
		ft_show(app);
		app->items.finish = 1;
		app->s_type = 'y';
	}
	else if (x == app->items.xpos_gate && \
			y == app->items.ypos_gate)
	{
		ft_putstr_fd("Can't eat flames! You're not a dragon:)!\n", 1);
		ft_deadhead(app, app->s_type);
		ft_freegame(app);
	}
	if (x == app->items.xpos_gate && \
		y == app->items.ypos_gate && \
		app->items.finish == 1)
	{
		ft_putstr_fd("You've reached the exit gate!\n", 1);
		ft_freegame(app);
	}
}
