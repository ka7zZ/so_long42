/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:11 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/05 16:09:17 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	show_enemy_seq(t_data *app, int n, int x, int y)
{
	t_seg	*buf;

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
	deploy_image(app, buf->img, buf->x, buf->y);
	free(buf->img);
	free(buf);
}

static int	enemy(t_data *app)
{
	t_list		*ptr;
	t_seg		*buf;
	static int	n = 0;
	int			temp;

	n++;
	if (n == 5)
		n = 1;
	ptr = app->items.enemies;
	temp = n;
	while (ptr && temp--)
	{
		buf = ptr->content;
		show_enemy_seq(app, n, buf->x, buf->y);
		ptr = ptr->next;
	}
	return (0);
}

int	check_enemy(t_data *app, int x, int y)
{
	t_list	*item;
	t_seg	*ptr;

	enemy(app);
	item = app->items.enemies;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == x && ptr->y == y)
		{
			dead_head(app, app->s_type);
			ft_putstr_fd("Ooops, enemy eated!\n", 1);
			return (1);
		}
		item = item->next;
	}
	return (0);
}
