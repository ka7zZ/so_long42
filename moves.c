#include "so_long.h"

static void	show_moves(t_data *app)
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

static void	move_snake(t_data *app, char *type, int new_x, int new_y)
{
	t_list	*ptr;
	t_snake	*img;

	ptr = app->snake;
	app->sx_pos = new_x;
	app->sy_pos = new_y;
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
	if (ft_strncmp("food", type, 4))
	{
		add_body(app, app->sx_last, app->sy_last);
		deploy_image(app, img->img, app->sx_last, app->sy_last);
	}
	else
		deploy_image(app, app->walls.bg, app->sx_last, app->sy_last);
}



static int	check_wall(t_data *app, int new_x, int new_y)
{
	t_list	*item;
	t_wseg	*ptr;

	item = app->items.wseg;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == new_x && ptr->y == new_y)
			return (1);
		item = item->next;
	}
	return (0);
}

static int	check_enemy(t_data *app, int new_x, int new_y)
{
	t_list	*item;
	t_enemy	*ptr;

	item = app->items.enemies;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == new_x && ptr->y == new_y)
			return (1);
		item = item->next;
	}
	return (0);
}

int	check_body(t_data *app, int new_x, int new_y)
{
	t_list	*item;
	t_snake	*ptr;

	item = app->snake;
	while (item)
	{
		ptr = item->content;
		if (ptr->x == new_x && ptr->y == new_y)
			return (1);
		item = item->next;
	}
	return (0);
}

static int	check_food(t_data *app, int new_x, int new_y)
{
	t_list	*item;
	t_list	*buf;
	t_food	*ptr;
	int 	check;

	check = 0;
	item = app->items.food;
	while (item)
	{
		buf = item->next;
		ptr = item->content;
		if (ptr && ptr->x == new_x && ptr->y == new_y)
		{
			mlx_destroy_image(app->mlx, ptr->img);
			ft_lstdelone(item, free);
			check = 1;
		}
		item = buf;
	}
	return (check);
}

void	action(t_data *app, int new_x, int new_y)
{
	t_list	*ptr;
	t_snake	*buf;

	if (check_wall(app, new_x, new_y) || check_enemy(app, new_x, new_y) || !new_x || !new_y)
	{
		ft_printf("Game over!\n");
		free_game(app);
	}
	if (check_food(app, new_x, new_y))
	{
		move_snake(app, "food", new_x, new_y);
		show_moves(app);
		return ;
	}		
	move_snake(app, "normal", new_x, new_y);
}	
/*SKETCH OF DIRECTION MOVE
static void	direction_loop(t_data *app, int k)
{
	int		new_posx;
	int		new_posy;
	int		check;
	t_snake	*current_part;
	t_snake *next_part;
	t_food	*f_ptr;
	t_list	*ptr;
	t_list	*temp;

	check = 0;
	if (!app->start)
		app->start = 1;
	
	if (k == 'w')
	{
		show_moves(app);
		new_posx = app->snake->content->x;
		new_posy = app->snake->content->y - IMAGE;
		if (new_posy == 0)
			free_game(app);
		ptr = app->item.food;
		while (ptr)
		{
			temp = ptr->next;
			f_ptr = ptr->content;
			if (f_ptr->y == new_posy && f_ptr->x == new_posx)
			{
				mlx_destroy_image(app->mlx, f_ptr->img);
				free(f_ptr);
				free(ptr);
				check = 1;
			}
			ptr = temp;
		}
		ptr = app->snake;
		while (ptr)
		{
			temp = ptr->next;
			current_part = ptr->content;
			next_part = temp->content;
			deploy_image(app, s_ptr->img, new_posx, new_posy);
			next_part->x = current_part->x;
			next_part->y = current_part->y;
			current_part->x = new_posx;
			current_part->y = new_posy;
			deploy_image

		}
		 
	}
	if (k == 'a'){} // 1.check if the body is on the x - image's pixels + decrement x by image's pixels
	if (k == 's'){} // increment y by image's pixels
	if (k == 'd'){}
}
*/

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