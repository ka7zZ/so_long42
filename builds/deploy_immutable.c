/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_immutable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:21:13 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 15:11:51 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

static void	deploy_bg(t_data *app)
{
	int	y;
	int	x;

	assign_image(app, &(app->walls.bg), app->path.bg);
	y = IMAGE;
	while (y < app->ygw)
	{
		x = IMAGE;
		while (x < app->xgw)
		{
			deploy_image(app, app->walls.bg, x, y);
			x += IMAGE;
		}
		y += IMAGE;
	}
}

static void	deploy_corners(t_data *app)
{
	t_wbox				*img;
	t_sprites			*addr;
	
	img = &(app->walls);
	addr = &(app->path);
	assign_image(app, &(img->corner), addr->corner);
	assign_image(app, &(img->ver_up), addr->ver_up);
	assign_image(app, &(img->ver_down), addr->ver_down);
	assign_image(app, &(img->hor_left), addr->hor_left);
	assign_image(app, &(img->hor_right), addr->hor_right);
	deploy_image(app, img->corner, 0, 0);
	deploy_image(app, img->corner, 0, app->ygw - IMAGE);
	deploy_image(app, img->corner, app->xgw - IMAGE, 0);
	deploy_image(app, img->corner, app->xgw - IMAGE, app->ygw - IMAGE);
	deploy_image(app, img->ver_up, 0, IMAGE);
	deploy_image(app, img->ver_up, app->xgw - IMAGE, IMAGE);
	deploy_image(app, img->ver_down, 0, app->ygw - (IMAGE * 2));
	deploy_image(app, img->ver_down, app->xgw - IMAGE, app->ygw - (IMAGE * 2));
	deploy_image(app, img->hor_left, IMAGE, 0);
	deploy_image(app, img->hor_left, IMAGE, app->ygw - IMAGE);
	deploy_image(app, img->hor_right, app->xgw - (IMAGE * 2), 0);
	deploy_image(app, img->hor_right, app->xgw - (IMAGE * 2), app->ygw - IMAGE);
}

void    deploy_immutable(t_data *app)
{
	t_wbox				*img;
	t_sprites			*addr;
	int x;
	int y;

	img = &(app->walls);
	addr = &(app->path);
	x = IMAGE * 2;
	y = IMAGE * 2;
	deploy_bg(app);
	deploy_corners(app);
	assign_image(app, &(img->side_hor), addr->hor_wall);
	assign_image(app, &(img->side_ver), addr->ver_wall);
	while (x < (app->xgw - IMAGE * 2))
	{
		deploy_image(app, img->side_hor, x, app->ygw - IMAGE);
		deploy_image(app, img->side_hor, x, 0);
		x += IMAGE;
	}
	while (y < (app->ygw - IMAGE * 2))
	{
		deploy_image(app, img->side_ver, 0, y);
		deploy_image(app, img->side_ver, app->xgw - IMAGE, y);
		y += IMAGE;
	}
}
