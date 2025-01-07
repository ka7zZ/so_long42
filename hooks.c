#include "so_long.h"

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
    mlx_destroy_image(app->mlx, app->img_start);
    mlx_destroy_window(app->mlx, app->win);
    mlx_destroy_display(app->mlx);
    free(app->mlx);
    free(app);
    exit(0);
    return (0);
}

static int		on_escape(int keycode, t_data *app)
{
	if (keycode == XK_Escape)
    {
        exit(0);
    }
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
        mlx_destroy_window(app->mlx, app->win);
        game_window(app);
	}
    return 0;
}

void	start_hooks(t_data *app)
{
    mlx_hook(app->win, DestroyNotify, NoEventMask, free_start, app);
	mlx_key_hook(app->win, on_escape, app);
    mlx_mouse_hook(app->win, on_mouse_click, app);
}
