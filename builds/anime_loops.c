/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_loops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:57 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/15 16:19:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

void	assign_cases(t_data *app, void **image, int n)
{
	if (!n)
		assign_image(app, image, app->anime.enemy0);
	else if (n == 1)
		assign_image(app, image, app->anime.enemy1);
	else if (n == 2)
		assign_image(app, image, app->anime.enemy2);
	else if (n == 3)
		assign_image(app, image, app->anime.enemy3);
	else if (n == 4)
		assign_image(app, image, app->anime.enemy4);
}

int	enemy_loop(t_data *app)
{
	t_list	*ptr;
	t_list	*temp;
	t_enemy	*buf;
	t_enemy *buf_next;
	int		i;
	ptr = app->items.enemies;
	temp = NULL;
	i = 0;
	while (ptr)
	{
		if (ptr->next)
		{	
			temp = ptr->next;
			buf_next = temp->content;
		}
		buf = ptr->content;
		if (buf->img)
			mlx_destroy_image(app->mlx, buf->img);
		if (temp)
			deploy_image(app, buf_next->img, buf_next->x, buf_next->y);
		assign_cases(app, &buf->img, i);
		i++;
		ptr = temp;
	}
	return (0);
}

int	show_exit(t_data *app)
{
	t_list  *ptr;
	t_gate	*buf;

	ptr = app->items.gate;
	while (ptr)
	{
		buf = ptr->content;
		if (buf->img)
			deploy_image(app, buf->img, buf->x, buf->y);
		ptr = ptr->next;
	}
	app->items.finish = 1;
	return (0);
}
