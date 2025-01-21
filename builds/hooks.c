/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:30:38 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/21 16:37:16 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builds.h"

int		start_pressed(t_data *app, int keycode)
{
	if (app->win_game && \
		(keycode == XK_w || keycode == XK_Up || \
		keycode == XK_a || keycode == XK_Left || \
		keycode == XK_s || keycode == XK_Down || \
		keycode == XK_d || keycode == XK_Right))
		return (1);
	return (0);
}

static void	key_pressed(t_data *app)
{
	if (app->k_pressed == 'w')
	{
		app->new_x = app->xpos_snake;
		app->new_y = app->ypos_snake - IMAGE;
	}
	else if (app->k_pressed == 'a')
	{
		app->new_x = app->xpos_snake - IMAGE;
		app->new_y = app->ypos_snake;
	}
	else if (app->k_pressed == 's')
	{
		app->new_x = app->xpos_snake;
		app->new_y = app->ypos_snake + IMAGE;
	}
	else if (app->k_pressed == 'd')
	{
		app->new_x = app->xpos_snake + IMAGE;
		app->new_y = app->ypos_snake;
	}
}

static int	action(t_data *app)
{
	key_pressed(app);
	if (app->start == 1)
	{
		app->frames += 1;
		if (app->frames < FPS)
			return (0);
		app->frames = 0;
		app->s_type = 'g';
		if (check_body(app, app->new_x, app->new_y) == 0)
			free_game(app);
		else if (check_body(app, app->new_x, app->new_y) > 1)
			return (0);
		check_gate(app, app->new_x, app->new_y);
		if (check_wall(app, app->new_x, app->new_y))
			free_game(app);
		if (check_food(app, app->new_x, app->new_y))
			add_body(app, app->xlast_snake, app->ylast_snake);
		moving_around(app, app->new_x, app->new_y);
		app->xpos_snake = app->new_x;
		app->ypos_snake = app->new_y;    
	}
	return (0);
}


static int		on_keypress(int keycode, t_data *app)
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
	}
	return (0);
}

static int on_mouse_click(int button, int mouse_x, int mouse_y, t_data *app)
{
	int min_x = 354;
	int max_x = 719;
	int min_y = 848;
	int max_y = 983;
	int bttn;

	bttn = button;
	if (bttn)
		bttn = 0;
	if (mouse_x >= min_x && mouse_x <= max_x && mouse_y >= min_y && mouse_y <= max_y)
	{
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
	mlx_key_hook(app->win_game, on_keypress, app);
	mlx_hook(app->win_game, DestroyNotify, NoEventMask, free_game, app);
	mlx_loop_hook(app->mlx, action, app);
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