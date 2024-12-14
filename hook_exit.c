#include "so_long.h"

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
		mlx_destroy_window(app->mlx, app->win2);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		app->mlx = NULL;
	}
}

int		on_destroy(int keycode, t_data *app)
{
	exit(0);
	return (0);
}

int		on_escape(int keycode, t_data *app)
{
	if (keycode == XK_Escape)
        exit(0);
	return (0);
}