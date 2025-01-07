#include "so_long.h"
/*
static void	initalize_data(t_data *ptr)
{
	ptr->mlx = NULL;
	ptr->win1 = NULL;
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
*/

int main(void)
{
	t_data  		*app;	
	t_map			map;

    app = malloc(sizeof(t_data));
    if (!app)
    {
        ft_putstr_fd("Error: Memory allocation failed for app\n", 1);
        return 1;
    }  
	app->game = &map;
	initalize_data(app);
	checker(app, "assets/maps/round2.ber");
	init_win1(app);
	start_hooks(app);
	mlx_loop(app->mlx);
    if (app->img_start)
		mlx_destroy_image(app->mlx, app->img_start);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	return (0);
}
