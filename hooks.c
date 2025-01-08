#include "so_long.h"

static int		on_keypress(int keycode, t_data *app)
{
	if (keycode == XK_Escape && !app->win_game)
			free_start(app);
	if (keycode == XK_Escape)
			free_game(app);
	// if (!app->start)
	// 	app->start = 1;
	if ((keycode == XK_w || keycode == XK_Up) && app->win_game)
		ft_printf("W pressed!\n");
	if ((keycode == XK_a || keycode == XK_Left) && app->win_game)
		ft_printf("A pressed!\n");
	if ((keycode == XK_s || keycode == XK_Down) && app->win_game)
		ft_printf("S pressed!\n");
	if ((keycode == XK_d || keycode == XK_Right) && app->win_game)
		ft_printf("D pressed!\n");
	app->moves += 1;
	if (app->moves > 0)
		app->mv_str = ft_itoa(app->moves);
	deploy_image(app, app->item.black, IMAGE * 3, app->ygw);
	mlx_string_put(app->mlx, app->win_game, IMAGE * 3, app->ygw + 21, 0xFFFFFF, "Moves: ");
	mlx_string_put(app->mlx, app->win_game, IMAGE * 4, app->ygw + 21, 0xFFFFFF, app->mv_str);
	if (app->mv_str)
		free(app->mv_str);
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

static int	on_mouse(int button, int mouse_x, int mouse_y, t_data *app)
{
	ft_printf("mouse_x -->> %d\nmouse_y -->> %d\n", mouse_x, mouse_y);
}
void	start_hooks(t_data *app)
{
	mlx_hook(app->win_start, DestroyNotify, NoEventMask, free_start, app);
	mlx_key_hook(app->win_start, on_keypress, app);
	mlx_mouse_hook(app->win_start, on_mouse_click, app);
}

void	game_hooks(t_data *app)
{
	mlx_hook(app->win_game, DestroyNotify, NoEventMask, free_game, app);
	mlx_key_hook(app->win_game, on_keypress, app);
	mlx_mouse_hook(app->win_game, on_mouse, app);
}
