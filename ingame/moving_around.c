/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_around.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:43 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/16 17:23:52 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

void	show_moves(t_data *app, int keycode)
{
	int x;
	int y;
	unsigned int color;

	if (app->win_game && \
		(keycode == XK_w || keycode == XK_Up || \
		keycode == XK_a || keycode == XK_Left || \
		keycode == XK_s || keycode == XK_Down || \
		keycode == XK_d || keycode == XK_Right))
	{
		x = IMAGE * 3;
		y = app->ypos_win + 21;
		color = 0xFFFFFF;
		app->moves += 1;
		ft_printf("Moves: %d\n", app->moves);
		if (app->moves > 0)
			app->mv = ft_itoa(app->moves);
		deploy_image(app, app->items.black, IMAGE * 3, app->ypos_win);
		mlx_string_put(app->mlx, app->win_game, x, y, color, "Moves: ");
		mlx_string_put(app->mlx, app->win_game, x + IMAGE, y, color, app->mv);
		if (app->mv)
			free(app->mv);
	}
}

void	moving_around(t_data *app, int x, int y)
{
	t_list	*ptr;
	t_snake	*img;

	ptr = app->snake;
	while (ptr)
	{
		img = ptr->content;
		deploy_image(app, img->img, x, y);
		app->xlast_snake = img->x;
		app->ylast_snake = img->y;
		img->x = x;
		img->y = y;
		x = app->xlast_snake;
		y = app->ylast_snake;
		ptr = ptr->next;
	}
	deploy_image(app, app->walls.bg, app->xlast_snake, app->ylast_snake);
}

/*RULES OF CHANGING DIRECTION
	

NEW_POS DETERMINATION:
		in case of W
			XPLAN - same
			YPLAN - y - block
		in case of S
			XPLAN - same
			YPLAN - y + block
		in case of A
			XPLAN - x - block
			YPLAN - same
		in case of D
			XPLAN - x - block
			YPLAN - same
PLAN:
		1.check if the body is on the moving directon
			-> if it is: don't do anything, also don't increment moves;

		2.check if there is exit_door
			-> if there is start_gate: 	destroy image of start_gate
										put the image of the snake there
										put the image of the start_gate again
										
			-> if there is exit_gate: destroy one at the time the snake and after this put an image with CONGRATS
			-> increment moves;
			-> 
		3.check if there is a wall or enemy
			-> if there is: change the snake into yellow
			-> increment moves;
		4.check if there is a food
			-> if there is: check if there is any food left -> start_gate/exit_gate;
							destroy image of the food;
							put the snake image on the food site.
			-> increment moves
	
																		
						

*/