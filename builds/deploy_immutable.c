/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_immutable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:21:13 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 13:09:53 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	deploy_bg(t_data *app)
{
	int	y;
	int	x;

	assign_image(app, &(app->walls.bg), app->path.bg);
	y = IMG;
	while (y < app->ylen_win)
	{
		x = IMG;
		while (x < app->xlen_win)
		{
			deploy_image(app, app->walls.bg, x, y);
			x += IMG;
		}
		y += IMG;
	}
}

static void	deploy_corners(t_data *app)
{
	t_wbox		*img;
	t_image		*addr;
	int			ext;

	ext = IMG * 2;
	img = &(app->walls);
	addr = &(app->path);
	assign_image(app, &(img->corner), addr->corner);
	assign_image(app, &(img->ver_up), addr->ver_up);
	assign_image(app, &(img->ver_down), addr->ver_down);
	assign_image(app, &(img->hor_left), addr->hor_left);
	assign_image(app, &(img->hor_right), addr->hor_right);
	deploy_image(app, img->corner, 0, 0);
	deploy_image(app, img->corner, 0, app->ylen_win - IMG);
	deploy_image(app, img->corner, app->xlen_win - IMG, 0);
	deploy_image(app, img->corner, app->xlen_win - IMG, app->ylen_win - IMG);
	deploy_image(app, img->ver_up, 0, IMG);
	deploy_image(app, img->ver_up, app->xlen_win - IMG, IMG);
	deploy_image(app, img->ver_down, 0, app->ylen_win - ext);
	deploy_image(app, img->ver_down, app->xlen_win - IMG, app->ylen_win - ext);
	deploy_image(app, img->hor_left, IMG, 0);
	deploy_image(app, img->hor_left, IMG, app->ylen_win - IMG);
	deploy_image(app, img->hor_right, app->xlen_win - ext, 0);
	deploy_image(app, img->hor_right, app->xlen_win - ext, app->ylen_win - IMG);
}

void	deploy_immutable(t_data *app)
{
	t_wbox		*img;
	t_image		*addr;
	int			x;
	int			y;

	img = &(app->walls);
	addr = &(app->path);
	x = IMG * 2;
	y = IMG * 2;
	deploy_bg(app);
	deploy_corners(app);
	assign_image(app, &(img->side_hor), addr->hor_wall);
	assign_image(app, &(img->side_ver), addr->ver_wall);
	while (x < (app->xlen_win - IMG * 2))
	{
		deploy_image(app, img->side_hor, x, app->ylen_win - IMG);
		deploy_image(app, img->side_hor, x, 0);
		x += IMG;
	}
	while (y < (app->ylen_win - IMG * 2))
	{
		deploy_image(app, img->side_ver, 0, y);
		deploy_image(app, img->side_ver, app->xlen_win - IMG, y);
		y += IMG;
	}
}
