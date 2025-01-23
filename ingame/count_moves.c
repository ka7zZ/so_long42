/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:32:59 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 13:08:52 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_moves(t_data *app)
{
	int				x;
	int				y;
	unsigned int	color;

	x = IMG * 3;
	y = app->ylen_win + 21;
	color = 0xFFFFFF;
	app->moves += 1;
	ft_printf("Moves: %d\n", app->moves);
	if (app->moves > 0)
		app->mv = ft_itoa(app->moves);
	deploy_image(app, app->items.black, IMG * 3, app->ylen_win);
	mlx_string_put(app->mlx, app->win_game, x, y, color, "Moves: ");
	mlx_string_put(app->mlx, app->win_game, x + IMG, y, color, app->mv);
	if (app->mv)
		free(app->mv);
}
