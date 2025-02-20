/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwall_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:49 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/20 17:55:21 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"
# include "../../includes/so_long_bonus.h"

int	ft_checkwall
(t_data *app, int x, int y)
{
	t_list	*item;
	t_wseg	*ptr;
	int		i;

	i = 0;
	if (!x || !y)
		i = 1;
	if (x == app->xlen_win - IMG || y == app->ylen_win - IMG)
		i = 1;
	item = app->items.wseg;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == x && ptr->y == y)
			i = 1;
		item = item->next;
	}
	if (i)
	{
		ft_deadhead(app, app->s_type);
		ft_putstr_fd("The bricks aren't digestives!\n", 1);
	}
	return (i);
}
