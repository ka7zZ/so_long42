/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:58 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/05 15:23:49 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	show_exit(t_data *app)
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
		deploy_image(app, buf->img, buf->x, buf->y);
	return (0);
}

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
	else if (x ==app->items.xpos_gate && \
			y == app->items.ypos_gate)
	{
		ft_putstr_fd("Can't eat flames! You're not a dragon:)!\n", 1);
		dead_head(app, app->s_type);
		free_game(app);	
	}
	if (x == app->items.xpos_gate && \
		y == app->items.ypos_gate && \
		app->items.finish == 1)
	{
		ft_printf("You've reached the exit gate!\n");
		free_game(app);
	}
}
