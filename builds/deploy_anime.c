/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_anime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:41:23 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/16 16:01:54 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

static t_enemy	*add_enemy_img(t_data *app, int n, int x, int y)
{
	t_enemy	*buf;
	
	buf = (t_enemy *)malloc(sizeof(t_enemy));
	if (!buf)
		free_game(app);
	if (!n)
		assign_image(app, &(buf->img), app->anime.enemy0);
	else if (n == 1)
		assign_image(app, &(buf->img), app->anime.enemy1);
	else if (n == 2)
		assign_image(app, &(buf->img), app->anime.enemy2);
	else if (n == 3)
		assign_image(app, &(buf->img), app->anime.enemy3);
	else if (n == 4)
		assign_image(app, &(buf->img), app->anime.enemy4);
	buf->x = x;
	buf->y = y;
	return (buf);
}

static t_gate	*add_gate_img(t_data *app, int n, int x, int y)
{
	t_gate	*buf;
	
	buf = (t_gate *)malloc(sizeof(t_gate));
	if (!buf)
		free_start(app);
	if (!n)
		assign_image(app, &(buf->img), app->anime.gate0);
	else if (n == 1)
		assign_image(app, &(buf->img), app->anime.gate1);
	else if (n == 2)
		assign_image(app, &(buf->img), app->anime.gate2);
	else if (n == 3)
		assign_image(app, &(buf->img), app->anime.gate3);
	else if (n == 4)
		assign_image(app, &(buf->img), app->anime.gate4);
	else if (n == 5)
		assign_image(app, &(buf->img), app->anime.gate5);
	else if (n == 6)
		assign_image(app, &(buf->img), app->anime.gate6);
	if (!buf->img)
		free_game(app);
	buf->x = x;
	buf->y = y;
	return (buf);
}

int	add_enemy_anim(t_data *app, int j, int i)
{
	t_list	*ptr;
	t_enemy	*buf;
	int		x;
	int		y;
	int		n;
	
	x = (X_BLOCK * j) - (IMAGE * 2);
	y = IMAGE * i;
	n = -1;
	ptr = app->items.enemies;
	while (++n < 6)
		ft_lstadd_back(&ptr, ft_lstnew(add_enemy_img(app, n, x, y)));
	n = -1;
	while (ptr)
	{
		buf = ptr->content;
		if (buf && ++n == 0)
			deploy_image(app, buf->img, buf->x, buf->y);
		ptr = ptr->next;
	}
	return (0);
}

void	deploy_gate_anim(t_data *app, int j, int i)
{
	t_list	*ptr;
	t_gate	*buf;
	int		n;
	
	app->items.xpos_gate = (X_BLOCK * j) - (IMAGE * 2);
	app->items.ypos_gate = IMAGE * i;
	n = -1;
	ptr = app->items.gate;
	while (++n < 7)
		ft_lstadd_back(&ptr, ft_lstnew(add_gate_img(app, n, app->items.xpos_gate, app->items.ypos_gate)));
	if (!ptr)
		free_game(app);
	n = -1;
	while (ptr)
	{
		buf = ptr->content;
		if (buf && ++n == 0)
			deploy_image(app, buf->img, buf->x, buf->y);
		ptr = ptr->next;
	}
}
