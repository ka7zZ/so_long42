/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_around.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:43 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/13 16:32:27 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ingame.h"

void	show_moves(t_data *app)
{
	app->moves += 1;
	if (app->moves > 0)
		app->mv_str = ft_itoa(app->moves);
	deploy_image(app, app->items.black, IMAGE * 3, app->ygw);
	mlx_string_put(app->mlx, app->win_game, IMAGE * 3, app->ygw + 21, 0xFFFFFF, "Moves: ");
	mlx_string_put(app->mlx, app->win_game, IMAGE * 4, app->ygw + 21, 0xFFFFFF, app->mv_str);
	if (app->mv_str)
		free(app->mv_str);
}

void	moving_around(t_data *app, int new_x, int new_y)
{
	t_list	*ptr;
	t_snake	*img;

	ptr = app->snake;
	while (ptr)
	{
		img = ptr->content;
		deploy_image(app, img->img, new_x, new_y);
		app->sx_last = img->x;
		app->sy_last = img->y;
		img->x = new_x;
		img->y = new_y;
		new_x = app->sx_last;
		new_y = app->sy_last;
		ptr = ptr->next;
	}
	deploy_image(app, app->walls.bg, app->sx_last, app->sy_last);
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