#include "so_long.h"
static int		on_destroy(int keycode, t_data *app)
{
    if (app->game->s.body != NULL)
    {
        ft_printf("aquiii estamosss");
        while (app->game->s.body != NULL)
        {
            free(app->game->s.body);
            app->game->s.body = app->game->s.body->next;
        }
        free(app->game->s.body);
    }
    exit(0);
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
        mlx_destroy_image(app->mlx, app->imgw1);
        mlx_destroy_window(app->mlx, app->win1);
        game_window(app);
	}
    return 0;
}


void	hooks(t_data *app)
{
    mlx_hook(app->win1, DestroyNotify, NoEventMask, on_destroy, app);
	mlx_key_hook(app->win1, on_escape, app);
    mlx_mouse_hook(app->win1, on_mouse_click, app);
}
