#include "so_long.h"

static int		on_escape(int keycode, t_data *app)
{
	if (keycode == XK_Escape)
		free_start(app);
	return (0);
}

static int on_mouse_click(int button, int mouse_x, int mouse_y, t_data *app)
{
	int min_x = 354;
	int max_x = 719;
	int min_y = 848;
	int max_y = 983;

	if (mouse_x >= min_x && mouse_x <= max_x && mouse_y >= min_y && mouse_y <= max_y)
	{
		mlx_destroy_image(app->mlx, app->img_start);
		mlx_destroy_window(app->mlx, app->win_start);
		game_window(app);
	}
	return 0;
}

void	start_hooks(t_data *app)
{
	mlx_hook(app->win_start, DestroyNotify, NoEventMask, free_start, app);
	mlx_key_hook(app->win_start, on_escape, app);
	mlx_mouse_hook(app->win_start, on_mouse_click, app);
}
