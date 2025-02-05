/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:23:38 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/05 16:09:30 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	deploy_snake(t_data *app, int j, int i)
{
	t_list		*ptr;
	t_seg		*buf;

	app->xpos_snake = (X_BLOCK * j) - (IMG * 2);
	app->ypos_snake = IMG * i;
	add_body(app, app->xpos_snake, app->ypos_snake);
	add_body(app, app->xpos_snake + IMG, app->ypos_snake);
	add_body(app, app->xpos_snake + (IMG * 2), app->ypos_snake);
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
	t_seg		*col;
	static int	n_food = 0;

	n_food++;
	col = (t_seg *)malloc(sizeof(t_seg));
	if (!col)
		free_game(app);
	if (n_food % 2 == 0)
		assign_image(app, &(col->img), app->path.egg);
	else
		assign_image(app, &(col->img), app->path.apple);
	col->x = (X_BLOCK * j) - IMG;
	col->y = IMG * i;
	ft_lstadd_back(&(app->items.food), ft_lstnew(col));
	deploy_image(app, col->img, col->x, col->y);
}

static void	deploy_wall(t_data *app, int j, int i)
{
	t_wseg	*wall_seg1;
	t_wseg	*wall_seg2;
	t_wseg	*wall_seg3;

	wall_seg1 = (t_wseg *)malloc(sizeof(t_wseg));
	wall_seg2 = (t_wseg *)malloc(sizeof(t_wseg));
	wall_seg3 = (t_wseg *)malloc(sizeof(t_wseg));
	if (!wall_seg1 || !wall_seg2 || !wall_seg3)
		free_game(app);
	wall_seg1->x = (X_BLOCK * j) - (IMG * 2);
	wall_seg1->y = IMG * i;
	wall_seg2->x = wall_seg1->x + IMG;
	wall_seg2->y = wall_seg1->y;
	wall_seg3->x = wall_seg2->x + IMG;
	wall_seg3->y = wall_seg2->y;
	deploy_image(app, app->walls.hor_left, wall_seg1->x, wall_seg1->y);
	deploy_image(app, app->walls.side_hor, wall_seg2->x, wall_seg2->y);
	deploy_image(app, app->walls.hor_right, wall_seg3->x, wall_seg3->y);
	ft_lstadd_back(&(app->items.wseg), ft_lstnew(wall_seg1));
	ft_lstadd_back(&(app->items.wseg), ft_lstnew(wall_seg2));
	ft_lstadd_back(&(app->items.wseg), ft_lstnew(wall_seg3));
}

static void	deploy_enemy(t_data *app, int j, int i)
{
	t_seg	*enemy;

	enemy = (t_seg *)malloc(sizeof(t_seg));
	if (!enemy)
		free_game(app);
	assign_image(app, &(enemy->img), app->path.enemy);
	enemy->x = (X_BLOCK * j) - IMG;
	enemy->y = IMG * i;
	ft_lstadd_back(&(app->items.enemies), ft_lstnew(enemy));
	deploy_image(app, enemy->img, enemy->x, enemy->y);
}

void	deploy_items(t_data *app)
{
	size_t	i;
	size_t	j;

	i = 0;
	assign_image(app, &(app->items.black), app->path.black);
	while (app->map[++i] != NULL)
	{
		if (app->map[i + 1] == NULL)
			break ;
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
				deploy_gate(app, j, i);
			else if (app->map[i][j] == 'I')
				deploy_enemy(app, j, i);
		}
	}
}
