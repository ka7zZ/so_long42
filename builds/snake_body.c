/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:00 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/16 17:57:37 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

int		dead_head(t_data *app, char type)
{
	t_list	*ptr;
	t_snake	*buf;


	ptr = app->snake;
	buf = ptr->content;
	mlx_destroy_image(app->mlx, buf->img);
	buf->img = NULL;
	if (type == 'g')
		assign_image(app, &(buf->img), app->path.snake_gdhead);
	if (type == 'y')
		assign_image(app, &(buf->img), app->path.snake_ydhead);
	if (buf->img)
		deploy_image(app, buf->img, buf->x, buf->y);
	else
		ft_printf("Error loading the protocols!\n");
	return (0);	
}

int		change_skin(t_data *app)
{
	t_list	*ptr;
	t_snake	*buf;
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
