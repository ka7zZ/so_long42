#include "so_long.h"

static int		on_keypress(int keycode, t_data *app)
{
	t_list		*snake;
	t_snake		*head;
	
	if ((keycode == XK_Return || keycode == XK_Escape) && !app->win_game)
	{
		if (keycode == XK_Escape)
			free_start(app);
		mlx_destroy_image(app->mlx, app->img_start);
		mlx_destroy_window(app->mlx, app->win_start);
		game_window(app);
		return (0);
	}
	if (keycode == XK_Escape)
			free_game(app);
	if ((keycode == XK_w || keycode == XK_Up) && app->win_game)
	{
		if (check_body(app, app->sx_pos, app->sy_pos - IMAGE))
			return (0);
		app->sy_pos -= IMAGE;
	}
	if ((keycode == XK_a || keycode == XK_Left) && app->win_game)
	{
		if (check_body(app, app->sx_pos - IMAGE, app->sy_pos))
			return (0);
		app->sx_pos -= IMAGE;
	}
	if ((keycode == XK_s || keycode == XK_Down) && app->win_game)
	{
		if (check_body(app, app->sx_pos, app->sy_pos + IMAGE))
			return (0);
		app->sy_pos += IMAGE;
	}
	if ((keycode == XK_d || keycode == XK_Right) && app->win_game)
	{
		if (check_body(app, app->sx_pos + IMAGE, app->sy_pos))
			return (0);
		app->sx_pos += IMAGE;
	}
	action(app, app->sx_pos, app->sy_pos);
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
	return (ft_printf("mouse_x -->> %d\nmouse_y -->> %d\n", mouse_x, mouse_y));
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
