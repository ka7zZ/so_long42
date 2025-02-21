/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeitems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:47:28 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/21 11:42:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../../includes/so_long.h"

static int	ft_free_gatewalls(t_data	*app)
{
	t_seg	*gbuf;
	t_wseg	*wbuf;
	t_list	*ptr;

	while (app->items.wseg)
	{
		ptr = app->items.wseg->next;
		wbuf = app->items.wseg->content;
		if (wbuf)
			free(wbuf);
		free(app->items.wseg);
		app->items.wseg = ptr;
	}
	while (app->items.gate)
	{
		ptr = app->items.gate->next;
		gbuf = app->items.gate->content;
		if (gbuf->img)
			mlx_destroy_image(app->mlx, gbuf->img);
		free(gbuf);
		free(app->items.gate);
		app->items.gate = ptr;
	}
	return (0);
}

static int	ft_freeimmutable(t_data *app)
{
	if (app->walls.bg)
		mlx_destroy_image(app->mlx, app->walls.bg);
	if (app->walls.corner)
		mlx_destroy_image(app->mlx, app->walls.corner);
	if (app->walls.ver_down)
		mlx_destroy_image(app->mlx, app->walls.ver_down);
	if (app->walls.ver_up)
		mlx_destroy_image(app->mlx, app->walls.ver_up);
	if (app->walls.hor_left)
		mlx_destroy_image(app->mlx, app->walls.hor_left);
	if (app->walls.hor_right)
		mlx_destroy_image(app->mlx, app->walls.hor_right);
	if (app->walls.side_hor)
		mlx_destroy_image(app->mlx, app->walls.side_hor);
	if (app->walls.side_ver)
		mlx_destroy_image(app->mlx, app->walls.side_ver);
	ft_free_gatewalls(app);
	return (0);
}

static int	ft_freefood(t_data *app)
{
	t_seg	*food_buf;
	t_list	*temp;

	if (app->items.food)
	{
		while (app->items.food)
		{
			temp = app->items.food->next;
			food_buf = app->items.food->content;
			if (food_buf)
			{
				mlx_destroy_image(app->mlx, food_buf->img);
				food_buf->img = NULL;
				free(food_buf);
			}
			free(app->items.food);
			app->items.food = temp;
		}
	}
	return (0);
}

static int	ft_freesnake(t_data *app)
{
	t_seg	*buf;
	t_list	*temp;

	while (app->snake)
	{
		temp = app->snake->next;
		buf = app->snake->content;
		if (buf)
		{
			mlx_destroy_image(app->mlx, buf->img);
			free(buf);
		}
		free(app->snake);
		app->snake = temp;
	}
	return (0);
}

int	ft_freeitems(t_data *app)
{
	t_seg	*buf;
	t_list	*ptr;

	ft_freeimmutable(app);
	ft_freefood(app);
	ft_freesnake(app);
	if (app->items.black)
		mlx_destroy_image(app->mlx, app->items.black);
	return (0);
}
