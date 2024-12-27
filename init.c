#include "so_long.h"

void	initalize_data(t_data *ptr)
{
	ptr->game = NULL;
	ptr->mlx = NULL;
	ptr->win1 = NULL;
	ptr->win2 = NULL;
	ptr->imgw1 = NULL;
	ptr->map = NULL;
	ptr->xw2 = 0;
	ptr->yw2 = 0;
}

void	wall_init(t_data *app)
{
	app->game->spr.walls.corner = "./assets/xpm/corner.xpm";
	app->game->spr.walls.hor_left = "./assets/xpm/hor_left.xpm";
	app->game->spr.walls.hor_wall = "./assets/xpm/hor_wall.xpm";
	app->game->spr.walls.hor_right = "./assets/xpm/hor_right.xpm";
	app->game->spr.walls.ver_up = "./assets/xpm/ver_up.xpm";
	app->game->spr.walls.ver_down = "./assets/xpm/ver_down.xpm";
	app->game->spr.walls.ver_wall = "./assets/xpm/ver_wall.xpm";
	app->game->spr.walls.bg = "./assets/xpm/background.xpm";
}

void	fseg_init(t_data *app)
{
	app->game->spr.fesg.egg = "./assets/xpm/egg.xpm";
	app->game->spr.fesg.apple = "./assets/xpm/food_apple.xpm";
	app->game->spr.fesg.enemy = "./assets/xpm/enemy.xpm";
	app->game->spr.fesg.exit_gate = "./assets/xpm/exit_gate.xpm";
	app->game->spr.fesg.start_gate = "./assets/xpm/start_gate.xpm";
	app->game->spr.fesg.snake_bdead = "./assets/xpm/snake_bdead.xpm";
	app->game->spr.fesg.snake_body = "./assets/xpm/snake_body.xpm";
	app->game->spr.fesg.snake_hdead = "./assets/xpm/snake_hdead.xpm";
	app->game->spr.fesg.snake_head = "./assets/xpm/snake_head.xpm";
	
}

void    init_win1(t_data *app)
{
	int	xpix;
	int	ypix;

	xpix = 1024;
	ypix = 1024;
	app->mlx = mlx_init();
	if (!app->mlx)
		return (ft_putstr_fd("Error loading mlx\n", 1));
    app->win1 = mlx_new_window(app->mlx, xpix, ypix, "Maze Munch");
    if (!app->win1)
		destroy_game(app);
    app->imgw1 = mlx_xpm_file_to_image(app->mlx, "assets/xpm/begin.xpm", &xpix, &ypix);
    if (!app->imgw1)
        destroy_game(app);
	mlx_put_image_to_window(app->mlx, app->win1, app->imgw1, 0, 0);
    hooks(app);
}
