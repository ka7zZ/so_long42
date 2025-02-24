/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glogic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:43 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/24 14:50:47 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	ft_keypressed(t_data *app)
{
	if (app->k_pressed == 'w')
	{
		app->new_x = app->xpos_snake;
		app->new_y = app->ypos_snake - IMG;
	}
	else if (app->k_pressed == 'a')
	{
		app->new_x = app->xpos_snake - IMG;
		app->new_y = app->ypos_snake;
	}
	else if (app->k_pressed == 's')
	{
		app->new_x = app->xpos_snake;
		app->new_y = app->ypos_snake + IMG;
	}
	else if (app->k_pressed == 'd')
	{
		app->new_x = app->xpos_snake + IMG;
		app->new_y = app->ypos_snake;
	}
}

static void	ft_movesnake(t_data *app, int x, int y)
{
	t_list	*ptr;
	t_seg	*snake_ptr;

	ptr = app->snake;
	while (ptr)
	{
		snake_ptr = ptr->content;
		ft_deployimg(app, snake_ptr->img, x, y);
		app->xlast_snake = snake_ptr->x;
		app->ylast_snake = snake_ptr->y;
		snake_ptr->x = x;
		snake_ptr->y = y;
		x = app->xlast_snake;
		y = app->ylast_snake;
		ptr = ptr->next;
	}
	ft_deployimg(app, app->walls.bg, app->xlast_snake, app->ylast_snake);
}

int	ft_glogic(t_data *app)
{
	ft_keypressed(app);
	if (app->start == 1)
	{
		app->frames += 1;
		if (app->frames < FPS)
			return (0);
		app->frames = 0;
		app->s_type = 'g';
		ft_checkgate(app, app->new_x, app->new_y);
		if (ft_checkwall(app, app->new_x, app->new_y))
			ft_freegame(app);
		if (!ft_checkbody(app, app->new_x, app->new_y))
			ft_freegame(app);
		else if (ft_checkbody(app, app->new_x, app->new_y) == 2)
			return (0);
		if (ft_checkfood(app, app->new_x, app->new_y))
			ft_addbody(app, app->xlast_snake, app->ylast_snake);
		ft_movesnake(app, app->new_x, app->new_y);
		app->xpos_snake = app->new_x;
		app->ypos_snake = app->new_y;
	}
	return (0);
}
