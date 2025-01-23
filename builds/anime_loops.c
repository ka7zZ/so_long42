/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_loops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:04:57 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 15:26:45 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	show_exit(t_data *app)
{
	t_list		*ptr;
	t_seg		*buf;
	static int	n = 0;
	int			temp;

	if (n == 9)
		n = 8;
	ptr = app->items.gate;
	n++;
	temp = n;
	while (ptr && temp--)
	{
		buf = ptr->content;
		ptr = ptr->next;
	}
	if (buf->img)
		deploy_image(app, buf->img, buf->x, buf->y);
	return (0);
}

int	enemy(t_data *app)
{
	t_list		*ptr;
	t_seg		*buf;
	static int	n = 0;
	int			temp;

	n++;
	if (n == 6)
		n = 1;
	ptr = app->items.enemies;
	temp = n;
	ft_putstr_fd("wowowwo\n", 1);
	ft_printf("n -->> %d\ntemp -->> %d\n", n, temp);
	while (ptr && temp--)
	{
		buf = ptr->content;
		ptr = ptr->next;
	}
	if (buf->img)
		deploy_image(app, buf->img, buf->x, buf->y);
	return (0);
}
