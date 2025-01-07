#include "so_long.h"

void	initalize_data(t_data *app)
{
	app->game = NULL;
	app->mlx = NULL;
	app->win = NULL;
	app->img_start = NULL;
	app->map = NULL;
	app->xgw = 0;
	app->ygw = 0;
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
    {
        ft_putstr_fd("Error loading mlx\n", 1);
		return ;
    }
    app->win = mlx_new_window(app->mlx, xpix, ypix, "Maze Munch");
    if (!app->win)
		destroy_game(app);
    app->img_start = mlx_xpm_file_to_image(app->mlx, "assets/xpm/begin.xpm", &xpix, &ypix);
    if (!app->img_start)
        destroy_game(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img_start, 0, 0);
}
