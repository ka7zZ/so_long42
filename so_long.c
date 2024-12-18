#include "so_long.h"

static void	initalize_data(t_data *ptr)
{
	ptr->mlx = NULL;
	ptr->win1 = NULL;
	ptr->win2 = NULL;
	ptr->imgw1 = NULL;
	ptr->map = NULL;
}

static void	win1_init(t_data *app)
{
	int		width;
	int		height;

	width = 1024;
	height = 1024;
	app->win1 = mlx_new_window(app->mlx, 1024, 1024, "Snake");
	if (!app->win1)
		destroy_game(app->mlx, map);
	app->imgw1 = mlx_xpm_file_to_image(app->mlx, 
									"./assets/xpm/begin.xpm", 
									&width, &height);
	mlx_put_image_to_window(app->mlx, app->win1, app->imgw1, 0, 0);
	win1_hooks(app);
}


int main(int ac, char *argv[])
{
	t_data	game;

	if (ac < 2)
		return(write(1, "Not enough arguments!\n", 22), 1);
	initalize_data(&game);
	checker(&game, argv[1]);
	game->mlx = mlx_init();
	if (!mlx)
		return (write(1, "Error loading the game!\n", 24), 1);
	win1_init(&game)
	return (1); 
}
