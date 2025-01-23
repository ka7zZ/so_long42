/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:22:36 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 11:50:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	add_body(t_data*app, int x, int y)
{
	t_seg		*seg;

	seg = (t_seg *)malloc(sizeof(t_seg));
	if (!seg)
		free_game(app);
	if (!app->snake)
		assign_image(app, &(seg->img), app->path.snake_ghead);
	else
		assign_image(app, &(seg->img), app->path.snake_gbody);
	seg->x = x;
	seg->y = y;
	ft_lstadd_back(&(app->snake), ft_lstnew(seg));
	return (0);
}
