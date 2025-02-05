/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:00 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/05 16:09:43 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	dead_head(t_data *app, char type)
{
	t_list	*ptr;
	t_seg	*buf;
	int		h;

	h = -1;
	ptr = app->snake;
	while (ptr)
	{
		buf = ptr->content;
		if (++h == 0)
		{
			mlx_destroy_image(app->mlx, buf->img);
			buf->img = NULL;
			if (type == 'g' && !buf->img)
				assign_image(app, &(buf->img), app->path.snake_gdhead);
			else if (type == 'y' && !buf->img)
				assign_image(app, &(buf->img), app->path.snake_ydhead);
			if (buf->img)
				deploy_image(app, buf->img, buf->x, buf->y);
			else
				ft_printf("Error loading the protocols!\n");
		}
		ptr = ptr->next;
	}
	return (0);
}

int	change_skin(t_data *app)
{
	t_list	*ptr;
	t_seg	*buf;
	int		i;

	i = 0;
	ptr = app->snake;
	while (ptr)
	{
		buf = ptr->content;
		mlx_destroy_image(app->mlx, buf->img);
		buf->img = NULL;
		if (i == 0)
			assign_image(app, &(buf->img), app->path.snake_yhead);
		else
			assign_image(app, &(buf->img), app->path.snake_ybody);
		deploy_image(app, buf->img, buf->x, buf->y);
		i++;
		ptr = ptr->next;
	}
	return (0);
}

int	add_body(t_data*app, int x, int y)
{
	t_seg		*seg;

	seg = (t_seg *)malloc(sizeof(t_seg));
	if (!seg)
		free_game(app);
	if (!app->snake)
		assign_image(app, &(seg->img), app->path.snake_ghead);
	else
		assign_image(app, &(seg->img), app->path.snake_gbody);
	seg->x = x;
	seg->y = y;
	ft_lstadd_back(&(app->snake), ft_lstnew(seg));
	return (0);
}
