/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:22:36 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 14:22:39 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

void	add_body(t_data*app, int x, int y)
{
	t_snake		*seg;

	seg = (t_snake *)malloc(sizeof(t_snake));
	if (!seg)
		free_game(app);
	if (!app->snake)
		assign_image(app, &(seg->img), app->path.snake_head);
	else
		assign_image(app, &(seg->img), app->path.snake_body);
	seg->x = x;
	seg->y = y;
	ft_lstadd_back(&(app->snake), ft_lstnew(seg));
	
}
