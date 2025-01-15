/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:18 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/15 10:52:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

int	check_body(t_data *app, int new_x, int new_y)
{
	t_list	*ptr;
	t_snake	*buf;
	int     i;

	i = 0;
	ptr = app->snake;
	while (ptr)
	{
		buf = ptr->content;
		if (buf->x == new_x && buf->y == new_y)
		{
			if (i == 1)
				return (1);
			else
			{
				ft_printf("Can't eat your own tale!\n");
				dead_head(app, app->s_type);
				return(0);
			}
		}
		i++;
		ptr = ptr->next;
	}
	return (2);
}
