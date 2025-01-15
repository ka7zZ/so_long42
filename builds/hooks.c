/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:30:38 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/15 16:36:18 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

static int	action (t_data *app, int new_x, int new_y)
{
	int		body;
	
	if (app->items.finish)
		change_skin(app);
	check_gate(app, new_x, new_y);
	body = check_body(app, new_x, new_y);
	if (!body)
		free_game(app);
	if (body == 1)
		return (0);
	app->sx_pos = new_x;
	app->sy_pos = new_y;
	if (check_wall(app, new_x, new_y))
		free_game(app);
	if (check_food(app, new_x, new_y))
		add_body(app, app->sx_last, app->sy_last);
	moving_around(app, new_x, new_y);
	show_moves(app);
	return (0);
}

static int	key_hook(t_data *app)
{
	if (app->w_press)
	{
		app->w_press = 0;
		app->sy_pos -= IMAGE;
		action(app, app->sx_pos, app->sy_pos);
	}
	if (app->a_press)
	{
		app->a_press = 0;
		app->sx_pos -= IMAGE;
		action(app, app->sx_pos, app->sy_pos);
	}
	if (app->s_press)
	{
		app->s_press = 0;
		app->sy_pos += IMAGE;
		action(app, app->sx_pos, app->sy_pos);
	}
	if (app->d_press)
	{
		app->d_press = 0;
		app->sx_pos += IMAGE;
		action(app, app->sx_pos, app->sy_pos);
	}
	return (0);
}

static int		on_keypress(int keycode, t_data *app)
{
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
		app->w_press = 1;
	if ((keycode == XK_a || keycode == XK_Left) && app->win_game)
		app->a_press = 1;
	if ((keycode == XK_s || keycode == XK_Down) && app->win_game)
		app->s_press = 1;
	if ((keycode == XK_d || keycode == XK_Right) && app->win_game)
		app->d_press = 1;
	key_hook(app);
	return (0);
}

static int on_mouse_click(int button, int mouse_x, int mouse_y, t_data *app)
{
	int min_x = 354;
	int max_x = 719;
	int min_y = 848;
	int max_y = 983;

	if (!button)
	{
		return (0);   
	}
	if (mouse_x >= min_x && mouse_x <= max_x && mouse_y >= min_y && mouse_y <= max_y)
	{
		mlx_destroy_image(app->mlx, app->img_start);
		mlx_destroy_window(app->mlx, app->win_start);
		game_window(app);
	}
	return 0;
}

int	start_hooks(t_data *app)
{
	mlx_hook(app->win_start, DestroyNotify, NoEventMask, free_start, app);
	mlx_key_hook(app->win_start, on_keypress, app);
	mlx_mouse_hook(app->win_start, on_mouse_click, app);
	return (0);
}

int	game_hooks(t_data *app)
{
	mlx_hook(app->win_game, DestroyNotify, NoEventMask, free_game, app);
	mlx_loop_hook(app->mlx, mlx_key_hook(app->win_game, on_keypress, app), app);
	return (0);
}



/* passing by gate with the snake 
	if (\
	new_x == app->items.xgate \
	&& new_y == app->items.ygate \
	&& !app->items.finish\
	)
		return (0);	
	*/