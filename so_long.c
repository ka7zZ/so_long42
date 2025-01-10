#include "so_long.h"


static void    init_win1(t_data *app)
{
	int	xpix;
	int	ypix;

	xpix = 1024;
	ypix = 1024;
	app->mlx = mlx_init();
	if (!app->mlx)
    {
        ft_putstr_fd("Error loading mlx\n", 1);
		return ;
    }
    app->win_start = mlx_new_window(app->mlx, xpix, ypix, "Maze Munch");
    if (!app->win_start)
		free_start(app);
    app->img_start = mlx_xpm_file_to_image(app->mlx, "assets/xpm/begin.xpm", &xpix, &ypix);
    if (!app->img_start)
        free_start(app);
	mlx_put_image_to_window(app->mlx, app->win_start, app->img_start, 0, 0);
}

int	free_start(t_data *app)
{
	int i;

	if (app->map)
	{
		i = -1;
		while(app->map[++i])
			free(app->map[i]);
		free(app->map);
	}
	if (app->img_start)
		mlx_destroy_image(app->mlx, app->img_start);
	if (app->win_start)
		mlx_destroy_window(app->mlx, app->win_start);
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	free(app);
	exit(0);
	return (0);
}

int main(void)
{
	t_data  		*app;	

    app = malloc(sizeof(t_data));
    if (!app)
    {
        ft_putstr_fd("Error: Memory allocation failed for app\n", 1);
        return 1;
    }
	ft_memset(app, 0, sizeof(t_data));
	//	CHECK MAP FORMAT
	checker(app, "assets/maps/round2.ber");
	//	INITIALISE FIRST WINDOW
	init_win1(app);
	//	DEFINING CLICK/KEYBOARD ACTIONS
	start_hooks(app);

	mlx_loop(app->mlx);

	return (0);
}
