/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_immutable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:21:13 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/21 11:41:45 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../../includes/so_long.h"

static void	ft_bg(t_data *app)
{
	int	y;
	int	x;

	ft_assignimg(app, &(app->walls.bg), app->path.bg);
	y = IMG;
	while (y < app->ylen_win)
	{
		x = IMG;
		while (x < app->xlen_win)
		{
			ft_deployimg(app, app->walls.bg, x, y);
			x += IMG;
		}
		y += IMG;
	}
}

static void	ft_corners(t_data *app)
{
	t_wbox		*img;
	t_image		*addr;
	int			ext;

	ext = IMG * 2;
	img = &(app->walls);
	addr = &(app->path);
	ft_assignimg(app, &(img->corner), addr->corner);
	ft_assignimg(app, &(img->ver_up), addr->ver_up);
	ft_assignimg(app, &(img->ver_down), addr->ver_down);
	ft_assignimg(app, &(img->hor_left), addr->hor_left);
	ft_assignimg(app, &(img->hor_right), addr->hor_right);
	ft_deployimg(app, img->corner, 0, 0);
	ft_deployimg(app, img->corner, 0, app->ylen_win - IMG);
	ft_deployimg(app, img->corner, app->xlen_win - IMG, 0);
	ft_deployimg(app, img->corner, app->xlen_win - IMG, app->ylen_win - IMG);
	ft_deployimg(app, img->ver_up, 0, IMG);
	ft_deployimg(app, img->ver_up, app->xlen_win - IMG, IMG);
	ft_deployimg(app, img->ver_down, 0, app->ylen_win - ext);
	ft_deployimg(app, img->ver_down, app->xlen_win - IMG, app->ylen_win - ext);
	ft_deployimg(app, img->hor_left, IMG, 0);
	ft_deployimg(app, img->hor_left, IMG, app->ylen_win - IMG);
	ft_deployimg(app, img->hor_right, app->xlen_win - ext, 0);
	ft_deployimg(app, img->hor_right, app->xlen_win - ext, app->ylen_win - IMG);
}

static void	ft_gategif(t_data *app, int n, int x, int y)
{
	t_seg	*buf;

	buf = (t_seg *)malloc(sizeof(t_seg));
	if (!buf)
		ft_freegame(app);
	buf->img = NULL;
	if (!n)
		ft_assignimg(app, &(buf->img), app->anime.gate0);
	else if (n == 1)
		ft_assignimg(app, &(buf->img), app->anime.gate1);
	else if (n == 2)
		ft_assignimg(app, &(buf->img), app->anime.gate2);
	else if (n == 3)
		ft_assignimg(app, &(buf->img), app->anime.gate3);
	else if (n == 4)
		ft_assignimg(app, &(buf->img), app->anime.gate4);
	else if (n == 5)
		ft_assignimg(app, &(buf->img), app->anime.gate5);
	if (!buf->img)
		ft_freegame(app);
	buf->x = x;
	buf->y = y;
	ft_lstadd_back(&(app->items.gate), ft_lstnew(buf));
}

void	ft_gate(t_data *app, int j, int i)
{
	t_list	*ptr;
	t_seg	*buf;
	int		n;

	app->items.xpos_gate = (X_BLOCK * j) - IMG;
	app->items.ypos_gate = IMG * i;
	n = -1;
	while (++n < 6)
		ft_gategif(app, n, app->items.xpos_gate, app->items.ypos_gate);
	ptr = app->items.gate;
	if (!ptr)
		ft_freegame(app);
	n = -1;
	while (ptr)
	{
		buf = ptr->content;
		if (buf && ++n == 0)
			ft_deployimg(app, buf->img, buf->x, buf->y);
		ptr = ptr->next;
	}
}

void	ft_immutable(t_data *app)
{
	t_wbox		*img;
	t_image		*addr;
	int			x;
	int			y;

	img = &(app->walls);
	addr = &(app->path);
	x = IMG * 2;
	y = IMG * 2;
	ft_bg(app);
	ft_corners(app);
	ft_assignimg(app, &(img->side_hor), addr->hor_wall);
	ft_assignimg(app, &(img->side_ver), addr->ver_wall);
	while (x < (app->xlen_win - IMG * 2))
	{
		ft_deploy_img(app, img->side_hor, x, app->ylen_win - IMG);
		ft_deploy_img(app, img->side_hor, x, 0);
		x += IMG;
	}
	while (y < (app->ylen_win - IMG * 2))
	{
		ft_deploy_img(app, img->side_ver, 0, y);
		ft_deploy_img(app, img->side_ver, app->xlen_win - IMG, y);
		y += IMG;
	}
}
