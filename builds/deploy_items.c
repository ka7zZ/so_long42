/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:38 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/15 13:11:36 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

static void deploy_snake(t_data *app, int j, int i)
{
	t_list		*ptr;
	t_snake		*buf;
	
	app->sx_pos = (X_BLOCK * j) - (IMAGE * 2); // moving the head in the first position of X_BLOCK
	app->sy_pos = IMAGE * i;
	add_body(app, app->sx_pos, app->sy_pos);
	add_body(app, app->sx_pos + IMAGE, app->sy_pos);
	add_body(app, app->sx_pos + (IMAGE * 2), app->sy_pos);
	ptr = app->snake;
	while (ptr != NULL)
	{
		buf = ptr->content;
		deploy_image(app, buf->img, buf->x, buf->y);
		ptr = ptr->next;
	}
	app->s_type = 'g';
}

static void	deploy_col(t_data *app, int j, int i)
{
	t_food		*col;
	static int	n_food = 0;

	n_food++;
	col = (t_food *)malloc(sizeof(t_food));
	if (!col)
		free_start(app);
	if (n_food % 2 == 0)
		assign_image(app, &(col->img), app->path.egg);
	else
		assign_image(app, &(col->img), app->path.apple);
	col->x = (X_BLOCK * j) - (IMAGE * 2);
	col->y = IMAGE * i;
	ft_lstadd_back(&(app->items.food), ft_lstnew(col));	
	deploy_image(app, col->img, col->x, col->y);
}

static void	deploy_wall(t_data *app, int j, int i)
{
	t_wseg		*wall_seg1;
	t_wseg		*wall_seg2;
	t_wseg		*wall_seg3;
	
	wall_seg1 = (t_wseg *)malloc(sizeof(t_wseg));
	wall_seg2 = (t_wseg *)malloc(sizeof(t_wseg));
	wall_seg3 = (t_wseg *)malloc(sizeof(t_wseg));
	if (!wall_seg1 || !wall_seg2 || !wall_seg3)
		free_game(app);
	wall_seg1->x = (X_BLOCK * j) - (IMAGE * 2);
	wall_seg1->y = IMAGE * i;
	wall_seg2->x = wall_seg1->x + IMAGE;
	wall_seg2->y = wall_seg1->y;
	wall_seg3->x = wall_seg2->x + IMAGE;
	wall_seg3->y = wall_seg2->y;
	deploy_image(app, app->walls.hor_left, wall_seg1->x, wall_seg1->y);
	deploy_image(app, app->walls.side_hor, wall_seg2->x, wall_seg2->y);
	deploy_image(app, app->walls.hor_right, wall_seg3->x, wall_seg3->y);
	ft_lstadd_back(&(app->items.wseg), ft_lstnew(wall_seg1));
	ft_lstadd_back(&(app->items.wseg), ft_lstnew(wall_seg2));
	ft_lstadd_back(&(app->items.wseg), ft_lstnew(wall_seg3));
}

void		deploy_items(t_data *app)
{
	size_t	i;
	size_t	j;

	i = 0;
	assign_image(app, &(app->items.black), app->path.black);
	while(app->map[++i] != NULL)
	{
		if (app->map[i + 1] == NULL)
			break;
		j = 0;
		while (app->map[i][++j] != '\0' && j < ft_strlen(app->map[i]) - 2)
		{
			if (app->map[i][j] == 'C')
				deploy_col(app, j, i);
			else if (app->map[i][j] == 'P')
				deploy_snake(app, j, i);
			else if (app->map[i][j] == '1' && app->map[i + 1] != NULL)
				deploy_wall(app, j, i);
			else if (app->map[i][j] == 'E')
				deploy_gate_anim(app, j, i);
			else if (app->map[i][j] == 'I')
				add_enemy_anim(app, j, i);
		}		
	}
}
