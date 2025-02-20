/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snake_body_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:00 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/20 17:38:59 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/so_long.h"
# include "../../includes/so_long_bonus.h"

int	ft_deadhead(t_data *app, char type)
{
	t_list	*ptr;
	t_seg	*buf;
	int		h;

	h = -1;
	ptr = app->snake;
	while (ptr)
	{
		buf = ptr->content;
		if (++h == 0)
		{
			mlx_destroy_image(app->mlx, buf->img);
			buf->img = NULL;
			if (type == 'g' && !buf->img)
				ft_assignimg(app, &(buf->img), app->path.snake_gdhead);
			else if (type == 'y' && !buf->img)
				ft_assignimg(app, &(buf->img), app->path.snake_ydhead);
			if (buf->img)
				ft_deployimg(app, buf->img, buf->x, buf->y);
			else
				ft_putstr_fd("Error loading the protocols!\n", 1);
		}
		ptr = ptr->next;
	}
	return (0);
}

int	ft_changeskin(t_data *app)
{
	t_list	*ptr;
	t_seg	*buf;
	int		i;

	i = 0;
	ptr = app->snake;
	while (ptr)
	{
		buf = ptr->content;
		mlx_destroy_image(app->mlx, buf->img);
		buf->img = NULL;
		if (i == 0)
			ft_assignimg(app, &(buf->img), app->path.snake_yhead);
		else
			ft_assignimg(app, &(buf->img), app->path.snake_ybody);
		ft_deployimg(app, buf->img, buf->x, buf->y);
		i++;
		ptr = ptr->next;
	}
	return (0);
}

int	ft_addbody(t_data*app, int x, int y)
{
	t_seg		*seg;

	seg = (t_seg *)malloc(sizeof(t_seg));
	if (!seg)
		ft_freegame(app);
	if (!app->snake)
		ft_assignimg(app, &(seg->img), app->path.snake_ghead);
	else
		ft_assignimg(app, &(seg->img), app->path.snake_gbody);
	seg->x = x;
	seg->y = y;
	ft_lstadd_back(&(app->snake), ft_lstnew(seg));
	return (0);
}
