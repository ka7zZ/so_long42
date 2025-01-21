/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_anime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:41:23 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/21 17:40:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

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
	else if (n == 6)
		assign_image(app, &(buf->img), app->anime.gate6);
	else if (n == 7)
		assign_image(app, &(buf->img), app->anime.gate7);
	if (!buf->img)
		free_game(app);
	buf->x = x;
	buf->y = y;
	ft_lstadd_back(&(app->items.gate), ft_lstnew(buf));
}

void	deploy_gate_anim(t_data *app, int j, int i)
{
	t_list	*ptr;
	t_seg	*buf;
	int		n;
	
	app->items.xpos_gate = (X_BLOCK * j) - IMAGE;
	app->items.ypos_gate = IMAGE * i;
	n = -1;
	while (++n < 8)
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
