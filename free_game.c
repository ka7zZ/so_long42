#include "so_long.h"

void    destroy_walls(t_data *app)
{
    if (app->game->wall.bg)
        mlx_destroy_image(app->mlx, app->game->wall.bg);
    if (app->game->wall.side_hor)
        mlx_destroy_image(app->mlx, app->game->wall.side_hor);
    if (app->game->wall.side_ver)
        mlx_destroy_image(app->mlx, app->game->wall.side_ver);
    if (app->game->wall.ud_left)
        mlx_destroy_image(app->mlx, app->game->wall.ud_left);
    if (app->game->wall.ud_right)
        mlx_destroy_image(app->mlx, app->game->wall.ud_right);
    if (app->game->wall.lr_up)
        mlx_destroy_image(app->mlx, app->game->wall.lr_up);
    if (app->game->wall.lr_down)
        mlx_destroy_image(app->mlx, app->game->wall.lr_down);
    if (app->game->wall.corner)
        mlx_destroy_image(app->mlx, app->game->wall.corner);
}
/*
void    destroy_items(t_data *app)
{
    if (app->game->item.enemy)
        mlx_destroy_image(app->mlx, app->game->item.enemy);
    if (app->game->item.exit_gate)
        mlx_destroy_image(app->mlx, app->game->item.exit_gate);
    if (app->game->item.food)
        mlx_destroy_image(app->mlx, app->game->item.food);
}

void    destroy_snake(t_data *app)
{
    t_snake *snake;
    t_sbody *buff;

    snake = &(app->game->s);
    if (snake->head)
    {
        mlx_destroy_image(app->mlx, snake->head);
        snake->head = NULL;
    }
    while (snake->ptr)
    {
        buff = snake->ptr->next;
        if (snake->ptr->body)
            mlx_destroy_image(app->mlx, snake->ptr->body);
        free(snake->ptr);
        snake->ptr = buff;
    }
    free(snake->ptr);
}
*/

void	destroy_game(t_data *app)
{
	int i;

	i = -1;
	while (app->map[++i] != NULL)
		free(app->map[i]);
	if (app->imgw1)
		mlx_destroy_image(app->mlx, app->imgw1);
	if (app->win1)
		mlx_destroy_window(app->mlx, app->win1);
	if (app->win2)
    {
        destroy_walls(app);
		mlx_destroy_window(app->mlx, app->win2);
	}
    if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		app->mlx = NULL;
	}
}
