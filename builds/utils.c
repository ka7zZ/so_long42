/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:32:28 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 14:47:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

void	assign_image(t_data *app, void **image, char *addr)
{
	int width;
	int height;

	if (addr == NULL)
		exit(0);
	*image = mlx_xpm_file_to_image(app->mlx, addr, &width, &height);
	if (!(*image))
		free_game(app);
}

void	deploy_image(t_data *app, void *image, int x, int y)
{
	mlx_put_image_to_window(app->mlx, app->win_game, image, x, y);
}