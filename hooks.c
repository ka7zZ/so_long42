#include "so_long.h"

static int		on_destroy(int keycode, t_data *app)
{
    ft_printf("woowoooondestrooy\n");
    if (app->win1 && keycode == 17)
    {
        ft_printf("now there win1\n");
        exit(0);
    }
    ft_printf("after first if\n");
    if (app->win2 && keycode == 17)
    {
        ft_printf("heereeee in else if of destroy\n");
        mlx_clear_window(app->mlx, app->win2);
    }
	return (0);
}

static int		on_escape(int keycode, t_data *app)
{
	if (keycode == XK_Escape)
    {
        ft_printf("heree on escapeee");
        if (app->win2)
            mlx_clear_window(app->mlx, app->win2);
        else if (app->win1)
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
        if (!app->win2)	
            game_window(app);
        else
            ft_printf("Already initialized!\n");
	}
    return 0;
}


void	hooks(t_data *app)
{
    mlx_hook(app->win1, 17, 0, on_destroy, app);
	mlx_key_hook(app->win1, on_escape, app);
    mlx_mouse_hook(app->win1, on_mouse_click, app);
}