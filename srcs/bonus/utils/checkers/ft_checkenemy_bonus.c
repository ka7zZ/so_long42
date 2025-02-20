/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkenemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:11 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/20 17:49:08 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	ft_enemygif(t_data *app, int n, int x, int y)
{
	t_seg	*buf;

	buf = (t_seg *)malloc(sizeof(t_seg));
	if (!buf)
		ft_freegame(app);
	buf->img = NULL;
	if (!n)
		ft_assignimg(app, &(buf->img), app->anime.enemy0);
	else if (n == 1)
		ft_assignimg(app, &(buf->img), app->anime.enemy1);
	else if (n == 2)
		ft_assignimg(app, &(buf->img), app->anime.enemy2);
	else if (n == 3)
		ft_assignimg(app, &(buf->img), app->anime.enemy3);
	else if (n == 4)
		ft_assignimg(app, &(buf->img), app->anime.enemy4);
	if (!buf->img)
		ft_freegame(app);
	buf->x = x;
	buf->y = y;
	ft_deployimg(app, buf->img, buf->x, buf->y);
	if (buf->img)
		mlx_destroy_image(app->mlx, buf->img);
	free(buf);
}

static int	ft_enemy(t_data *app)
{
	t_list		*ptr;
	t_seg		*buf;
	static int	n = 0;
	int			temp;

	n++;
	if (n == 5)
		n = 0;
	ptr = app->items.enemies;
	temp = n;
	while (ptr && temp--)
	{
		buf = ptr->content;
		if (buf->img)
			ft_enemygif(app, n, buf->x, buf->y);
		ptr = ptr->next;
	}
	return (0);
}

int	ft_checkenemy(t_data *app, int x, int y)
{
	t_list	*item;
	t_seg	*ptr;

	item = app->items.enemies;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == x && ptr->y == y)
		{
			ft_deadhead(app, app->s_type);
			ft_putstr_fd("Ooops, enemy eated!\n", 1);
			return (1);
		}
		item = item->next;
	}
	ft_enemy(app);
	return (0);
}
