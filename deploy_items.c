/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_items.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:32:19 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/08 18:47:09 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static void	add_body(t_data*app, int x, int y)
{
	t_body		*seg;

	seg = (t_body *)malloc(sizeof(t_body));
	if (!seg)
		free_start(app);
	assign_image(app, &(seg->img), app->path.snake_body);
	seg->x = x;
	seg->y = y;
	ft_lstadd_back(&(app->snake.body), ft_lstnew(seg));
	
}

static void deploy_snake(t_data *app, int j, int i)
{
	int			size;
	t_list		*ptr;
	t_body		*buf;
	
	size = IMAGE;
	app->snake.x = (X_BLOCK * j) - (IMAGE * 2);
	app->snake.y = (Y_BLOCK * i);
	assign_image(app, &(app->snake.head), app->path.snake_head);
	deploy_image(app, app->snake.head, app->snake.x, app->snake.y);
	add_body(app, app->snake.x + size, app->snake.y);
	add_body(app, app->snake.x + (size * 2), app->snake.y);
	ptr = app->snake.body;
	while (ptr != NULL)
	{
		buf = ptr->content;
		deploy_image(app, buf->img, buf->x, buf->y);
		ptr = ptr->next;
	}
}

static void	deploy_gate(t_data *app, int j, int i)
{
	int					x;
	int					y;
	
	x = (X_BLOCK * j) - (IMAGE * 2);
	y = (Y_BLOCK * i) - IMAGE;
	assign_image(app, &(app->item.start_gate), app->path.start_gate);
	deploy_image(app, app->item.start_gate, x, y);
}

static void	deploy_collectibles(t_data *app, int j, int i)
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
	col->y = (Y_BLOCK * i) - IMAGE;
	ft_lstadd_back(&(app->item.food), ft_lstnew(col));	
	deploy_image(app, col->img, col->x, col->y);
}

void	deploy_items(t_data *app)
{
	int					i;
	int					j;
	int					map_width;

	i = 0;
	assign_image(app, &(app->item.black), app->path.black);
	map_width = ft_strlen(app->map[i]) - 1;
	while(app->map[++i] != NULL)
	{
		if (app->map[i + 1] == NULL)
			break;
		j = 0;
		while (app->map[i][++j] != '\0' && j < map_width - 1)
		{
			if (app->map[i][j] == 'C')
				deploy_collectibles(app, j, i);
			else if (app->map[i][j] == 'E')
				deploy_gate(app, j, i);
			else if (app->map[i][j] == 'P')
				deploy_snake(app, j, i);
		}		
	}
}
