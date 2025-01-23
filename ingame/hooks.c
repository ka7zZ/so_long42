/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:30:38 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/23 13:06:01 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	start_pressed(t_data *app, int keycode)
{
	if (app->win_game && \
		(keycode == XK_w || keycode == XK_Up || \
		keycode == XK_a || keycode == XK_Left || \
		keycode == XK_s || keycode == XK_Down || \
		keycode == XK_d || keycode == XK_Right))
		return (1);
	return (0);
}

static int	on_keypress(int keycode, t_data *app)
{
	if (keycode == XK_Return)
		game_window(app);
	if (keycode == XK_Escape && !app->win_game)
		free_start(app);
	if (keycode == XK_Escape)
		free_game(app);
	if (start_pressed(app, keycode))
	{
		if ((keycode == XK_w || keycode == XK_Up) && app->win_game)
			app->k_pressed = 'w';
		if ((keycode == XK_a || keycode == XK_Left) && app->win_game)
			app->k_pressed = 'a';
		if ((keycode == XK_s || keycode == XK_Down) && app->win_game)
			app->k_pressed = 's';
		if ((keycode == XK_d || keycode == XK_Right) && app->win_game)
			app->k_pressed = 'd';
		app->start = 1;
		count_moves(app);
	}
	return (0);
}

static int	on_mouse_click(int button, int mouse_x, int mouse_y, t_data *app)
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;
	int	bttn;

	min_x = 354;
	max_x = 719;
	min_y = 848;
	max_y = 983;
	bttn = button;
	if (bttn)
		bttn = 0;
	if (mouse_x >= min_x && mouse_x <= max_x && \
		mouse_y >= min_y && mouse_y <= max_y)
		game_window(app);
	return (0);
}

int	hooks(t_data *app)
{
	if (app->win_start)
	{
		mlx_hook(app->win_start, DestroyNotify, NoEventMask, free_start, app);
		mlx_key_hook(app->win_start, on_keypress, app);
		mlx_mouse_hook(app->win_start, on_mouse_click, app);
	}
	if (app->win_game)
	{
		mlx_key_hook(app->win_game, on_keypress, app);
		mlx_hook(app->win_game, DestroyNotify, NoEventMask, free_game, app);
		mlx_loop_hook(app->mlx, game_logic, app);
	}
	return (0);
}
