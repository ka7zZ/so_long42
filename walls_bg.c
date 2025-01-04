#include "so_long.h"

static void    deploy_corners(t_data *app)
{
	t_walls				*img;
	t_map_walls_addr	*addr;
	
	img = &(app->game->wall);
	addr = &(app->game->spr.walls);
	assign_image(app, &(img->corner), addr->corner);
	assign_image(app, &(img->lr_up), addr->ver_up);
	assign_image(app, &(img->lr_down), addr->ver_down);
	assign_image(app, &(img->ud_left), addr->hor_left);
	assign_image(app, &(img->ud_right), addr->hor_right);
	deploy_image(app, img->corner, 0, 0);
	deploy_image(app, img->corner, 0, app->yw2 - IMAGE);
	deploy_image(app, img->corner, app->xw2 - IMAGE, 0);
	deploy_image(app, img->corner, app->xw2 - IMAGE, app->yw2 - IMAGE);
	deploy_image(app, img->lr_up, 0, IMAGE);
	deploy_image(app, img->lr_up, app->xw2 - IMAGE, IMAGE);
	deploy_image(app, img->lr_down, 0, app->yw2 - (IMAGE * 2));
	deploy_image(app, img->lr_down, app->xw2 - IMAGE, app->yw2 - (IMAGE * 2));
	deploy_image(app, img->ud_left, IMAGE, 0);
	deploy_image(app, img->ud_left, IMAGE, app->yw2 - IMAGE);
	deploy_image(app, img->ud_right, app->xw2 - (IMAGE * 2), 0);
	deploy_image(app, img->ud_right, app->xw2 - (IMAGE * 2), app->yw2 - IMAGE);
}

static void    deploy_borders(t_data *app)
{
	t_walls				*img;
	t_map_walls_addr	*addr;
	int x;
	int y;

	img = &(app->game->wall);
	addr = &(app->game->spr.walls);
	x = IMAGE * 2;
	y = IMAGE * 2;
	deploy_corners(app);
	assign_image(app, &(img->side_hor), addr->hor_wall);
	assign_image(app, &(img->side_ver), addr->ver_wall);
	while (x < (app->xw2 - IMAGE * 2))
	{
		deploy_image(app, img->side_hor, x, app->yw2 - IMAGE);
		deploy_image(app, img->side_hor, x, 0);
		x += IMAGE;
	}
	while (y < (app->yw2 - IMAGE * 2))
	{
		deploy_image(app, img->side_ver, 0, y);
		deploy_image(app, img->side_ver, app->xw2 - IMAGE, y);
		y += IMAGE;
	}
}

void	deploy_immutable(t_data *app)
{
	t_map	map;

	app->game = &map;	
	wall_init(app);
	fseg_init(app);
	deploy_borders(app);
}
