/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_anime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:41:23 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 15:09:05 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	add_gate_seg(t_data *app, int n, int x, int y)
{
	t_seg	*buf;

	buf = (t_seg *)malloc(sizeof(t_seg));
	if (!buf)
		free_game(app);
	buf->img = NULL;
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
	if (!buf->img)
		free_game(app);
	buf->x = x;
	buf->y = y;
	ft_lstadd_back(&(app->items.gate), ft_lstnew(buf));
}

static void	add_enemy_seg(t_data *app, int n, int x, int y)
{
	t_seg *buf;

	buf = (t_seg *)malloc(sizeof(t_seg));
	if (!buf)
		free_game(app);
	buf->img = NULL;
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
	if (!buf->img)
		free_game(app);
	buf->x = x;
	buf->y = y;
	ft_lstadd_back(&(app->items.enemies), ft_lstnew(buf));
}

void	deploy_gate_anim(t_data *app, int j, int i)
{
	t_list	*ptr;
	t_seg	*buf;
	int		n;

	app->items.xpos_gate = (X_BLOCK * j) - IMG;
	app->items.ypos_gate = IMG * i;
	n = -1;
	while (++n < 6)
		add_gate_seg(app, n, app->items.xpos_gate, app->items.ypos_gate);
	ptr = app->items.gate;
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

void	deploy_enemy_anim(t_data *app, int j, int i)
{
	t_list	*ptr;
	t_seg	*buf;
	int		x;
	int		y;
	int		n;
	
	x = (X_BLOCK * j) - IMG;
	y = IMG * i;
	n = -1;
	while (++n < 5)
		add_enemy_seg(app, n, x, y);
	ptr = app->items.enemies;
	if (!ptr)
		free_game(app);
	while (ptr)
	{
		buf = ptr->content;
		if (buf && ++n == 0)
			deploy_image(app, buf->img, buf->x, buf->y);
		ptr = ptr->next;		
	}
}