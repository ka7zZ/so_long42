#include "so_long.h"

void	free_immutable(t_data *app)
{
	if (app->items.start_gate)
		mlx_destroy_image(app->mlx, app->items.start_gate);
	if (app->walls.bg)
		mlx_destroy_image(app->mlx, app->walls.bg);
	if (app->walls.corner)
		mlx_destroy_image(app->mlx, app->walls.corner);
	if (app->walls.ver_down)
		mlx_destroy_image(app->mlx, app->walls.ver_down);
	if (app->walls.ver_up)
		mlx_destroy_image(app->mlx, app->walls.ver_up);
	if (app->walls.hor_left)
		mlx_destroy_image(app->mlx, app->walls.hor_left);
	if (app->walls.hor_right)
		mlx_destroy_image(app->mlx, app->walls.hor_right);
	if (app->walls.side_hor)
		mlx_destroy_image(app->mlx, app->walls.side_hor);
	if (app->walls.side_ver)
		mlx_destroy_image(app->mlx, app->walls.side_ver);
	if (app->items.exit_gate)
		mlx_destroy_image(app->mlx, app->items.exit_gate);
}

void	free_enemies(t_data *app)
{
	t_enemy	*buf;
	t_list	*ptr;

	while (app->items.enemies)
	{
		ptr = app->items.enemies->next;
		buf = app->items.enemies->content;
		if (buf)
			free(buf);
		free(app->items.enemies);
		app->items.enemies = ptr;
	}
}

void	free_collectibles(t_data *app)
{
	t_food	*food_buf;
	t_list	*temp;
	
	if (app->items.food)
	{
		while (app->items.food)
		{
			temp = app->items.food->next;
			food_buf = app->items.food->content;
			if (food_buf)
			{
				mlx_destroy_image(app->mlx, food_buf->img);
				free(food_buf);
			}
			free(app->items.food);
			app->items.food = temp;	
		}
	}
}

void	free_snake(t_data *app)
{
	t_snake	*buf;
	t_list	*temp;
	
	while (app->snake)
	{
		temp = app->snake->next;
		buf = app->snake->content;
		if (buf)
		{
			mlx_destroy_image(app->mlx, buf->img);
			free(buf);
		}
		free(app->snake);
		app->snake = temp;
	}
}

void	free_wallseg(t_data	*app)
{
	t_wseg	*buf;
	t_list	*ptr;

	while (app->items.wseg)
	{
		ptr = app->items.wseg->next;
		buf = app->items.wseg->content;
		if (buf)
			free(buf);
		free(app->items.wseg);
		app->items.wseg = ptr;
	}
}
