/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:43 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 15:04:45 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	key_pressed(t_data *app)
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

static void	move_snake(t_data *app, int x, int y)
{
	t_list	*ptr;
	t_seg	*snake_ptr;

	ptr = app->snake;
	while (ptr)
	{
		snake_ptr = ptr->content;
		deploy_image(app, snake_ptr->img, x, y);
		app->xlast_snake = snake_ptr->x;
		app->ylast_snake = snake_ptr->y;
		snake_ptr->x = x;
		snake_ptr->y = y;
		x = app->xlast_snake;
		y = app->ylast_snake;
		ptr = ptr->next;
	}
	deploy_image(app, app->walls.bg, app->xlast_snake, app->ylast_snake);
}

int	game_logic(t_data *app)
{
	key_pressed(app);
	if (app->start == 1)
	{
		app->frames += 1;
		if (app->frames < FPS)
			return (0);
		app->frames = 0;
		app->s_type = 'g';
		enemy(app);
		if (check_body(app, app->new_x, app->new_y) == 0)
			free_game(app);
		else if (check_body(app, app->new_x, app->new_y) == 2)
			return (0);
		check_gate(app, app->new_x, app->new_y);
		if (check_wall(app, app->new_x, app->new_y))
			free_game(app);
		if (check_food(app, app->new_x, app->new_y))
			add_body(app, app->xlast_snake, app->ylast_snake);
		move_snake(app, app->new_x, app->new_y);
		app->xpos_snake = app->new_x;
		app->ypos_snake = app->new_y;
	}
	return (0);
}
