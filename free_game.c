#include "so_long.h"

static void	free_collectibles(t_data *app)
{
	t_food	*food_buf;
	t_list	*temp;
	
	if (app->item.food)
	{
		while (app->item.food)
		{
			temp = app->item.food->next;
			food_buf = app->item.food->content;
			if (food_buf)
			{
				mlx_destroy_image(app->mlx, food_buf->img);
				free(food_buf);
			}
			free(app->item.food);
			app->item.food = temp;	
		}
	}
}

static void	free_snake(t_data *app)
{
	t_body	*buf;
	t_list	*temp;
	
	if (app->snake.head)
		mlx_destroy_image(app->mlx, app->snake.head);
	if (app->snake.body)
	{
		while (app->snake.body)
		{
			temp = app->snake.body->next;
			buf = app->snake.body->content;
			if (buf)
			{
				mlx_destroy_image(app->mlx, buf->img);
				free(buf);
			}
			free(app->snake.body);
			app->snake.body = temp;
		}
	}
}

static void 	free_immutable(t_data *app)
{
	if (app->item.start_gate)
		mlx_destroy_image(app->mlx, app->item.start_gate);
	if (app->wall.bg)
		mlx_destroy_image(app->mlx, app->wall.bg);
	if (app->wall.corner)
		mlx_destroy_image(app->mlx, app->wall.corner);
	if (app->wall.lr_down)
		mlx_destroy_image(app->mlx, app->wall.lr_down);
	if (app->wall.lr_up)
		mlx_destroy_image(app->mlx, app->wall.lr_up);
	if (app->wall.ud_left)
		mlx_destroy_image(app->mlx, app->wall.ud_left);
	if (app->wall.ud_right)
		mlx_destroy_image(app->mlx, app->wall.ud_right);
	if (app->wall.side_hor)
		mlx_destroy_image(app->mlx, app->wall.side_hor);
	if (app->wall.side_ver)
		mlx_destroy_image(app->mlx, app->wall.side_ver);
	if (app->item.exit_gate)
		mlx_destroy_image(app->mlx, app->item.exit_gate);
	if (app->item.enemy)
		mlx_destroy_image(app->mlx, app->item.enemy);
}

int	free_game(t_data *app)
{
	int i;

	ft_printf("Eliberating memory...\n");
	if (app->map)
	{
		i = -1;
		while(app->map[++i])
			free(app->map[i]);
		free(app->map);
	}
	free_collectibles(app);
	ft_printf("1/4\n");
	free_snake(app);
	ft_printf("2/4\n");
	free_immutable(app);
	ft_printf("3/4\n");
	mlx_destroy_window(app->mlx, app->win_game);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	free(app);
	ft_printf("Completed!\n");
	exit(0);
	return (0);
}

int	free_start(t_data *app)
{
	int i;

	if (app->map)
	{
		i = -1;
		while(app->map[++i])
			free(app->map[i]);
		free(app->map);
	}
	if (app->img_start)
		mlx_destroy_image(app->mlx, app->img_start);
	if (app->win_start)
		mlx_destroy_window(app->mlx, app->win_start);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	free(app);
	exit(0);
	return (0);
}
