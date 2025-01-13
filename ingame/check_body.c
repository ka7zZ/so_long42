/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:18 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 15:22:23 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

int	check_body(t_data *app, int new_x, int new_y)
{
	t_list	*item;
	t_snake	*ptr;
	int     i;

	i = 0;
	item = app->snake;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == new_x && ptr->y == new_y)
		{
			if (i == 1)
				return (1);
			else
			{
				ft_printf("Can't eat your own tale!\n");
				return(0);
			}
		}
		i++;
		item = item->next;
	}
	return (2);
}
