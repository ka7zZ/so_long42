/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:47:28 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/16 18:07:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

static int	free_gw(t_data	*app)
{
	t_gate	*gbuf;
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
    free(app->items.wseg->content);
	while (app->items.gate)
	{
		ptr = app->items.gate->content;
		gbuf = ptr->content;
		if (gbuf)
			free(gbuf);
		free(app->items.gate);
		app->items.gate = ptr;
	}
    free(app->items.gate->content);
    return (free(app->items.wseg), free(app->items.gate), 0);
}

static int	free_immutable(t_data *app)
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
    free_gw(app);
    return (0);
}

static int	free_collectibles(t_data *app)
{
	t_food	*food_buf;
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
				free(food_buf);
			}
			free(app->items.food);
			app->items.food = temp;	
		}
        if (app->items.food)
            free(app->items.food->content);
        free(app->items.food);
	}
    free_immutable(app);
    return (0);
}

static int	free_snake(t_data *app)
{
	t_snake	*buf;
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
    free(app->snake->content);
    free(app->snake);
    return (0);
}

int	free_items(t_data *app)
{
	t_enemy	*buf;
	t_list	*ptr;

    free_collectibles(app);
    free_snake(app);
	if (app->items.enemies)
    {
        while (app->items.enemies)
        {
            ptr = app->items.enemies->next;
            buf = app->items.enemies->content;
            if (buf)
                free(buf);
            free(app->items.enemies);
            app->items.enemies = ptr;
        }
        free(app->items.enemies->content);   
        free(app->items.enemies);
    }
    if (app->items.black)
        mlx_destroy_image(app->mlx, app->items.black);
    return (0);
}
