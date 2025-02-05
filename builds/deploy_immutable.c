/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_immutable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:21:13 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/05 15:27:43 by aghergut         ###   ########.fr       */
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

static void	add_gate_seg(t_data *app, int n, int x, int y)
{
	t_seg	*buf;

	buf = (t_seg *)malloc(sizeof(t_seg));
	if (!buf)
		free_game(app);
	buf->img = NULL;
	if (!n)
		assign_image(app, &(buf->img), app->anime.gate0);
	else if (n == 1)
		assign_image(app, &(buf->img), app->anime.gate1);
	else if (n == 2)
		assign_image(app, &(buf->img), app->anime.gate2);
	else if (n == 3)
		assign_image(app, &(buf->img), app->anime.gate3);
	else if (n == 4)
		assign_image(app, &(buf->img), app->anime.gate4);
	else if (n == 5)
		assign_image(app, &(buf->img), app->anime.gate5);
	if (!buf->img)
		free_game(app);
	buf->x = x;
	buf->y = y;
	ft_lstadd_back(&(app->items.gate), ft_lstnew(buf));
}

void	deploy_gate(t_data *app, int j, int i)
{
	t_list	*ptr;
	t_seg	*buf;
	int		n;

	app->items.xpos_gate = (X_BLOCK * j) - IMG;
	app->items.ypos_gate = IMG * i;
	n = -1;
	while (++n < 6)
		add_gate_seg(app, n, app->items.xpos_gate, app->items.ypos_gate);
	ptr = app->items.gate;
	if (!ptr)
		free_game(app);
	n = -1;
	while (ptr)
	{
		buf = ptr->content;
		if (buf && ++n == 0)
			deploy_image(app, buf->img, buf->x, buf->y);
		ptr = ptr->next;
	}
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
