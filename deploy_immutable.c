#include "so_long.h"

static void	deploy_bg(t_data *app)
{
	int	y;
	int	x;

	assign_image(app, &(app->wall.bg), app->path.bg);
	y = IMAGE;
	while (y < app->ygw)
	{
		x = IMAGE;
		while (x < app->xgw)
		{
			deploy_image(app, app->wall.bg, x, y);
			x += IMAGE;
		}
		y += IMAGE;
	}
}

static void	deploy_corners(t_data *app)
{
	t_walls				*img;
	t_sprites			*addr;
	
	img = &(app->wall);
	addr = &(app->path);
	assign_image(app, &(img->corner), addr->corner);
	assign_image(app, &(img->lr_up), addr->ver_up);
	assign_image(app, &(img->lr_down), addr->ver_down);
	assign_image(app, &(img->ud_left), addr->hor_left);
	assign_image(app, &(img->ud_right), addr->hor_right);
	deploy_image(app, img->corner, 0, 0);
	deploy_image(app, img->corner, 0, app->ygw - IMAGE);
	deploy_image(app, img->corner, app->xgw - IMAGE, 0);
	deploy_image(app, img->corner, app->xgw - IMAGE, app->ygw - IMAGE);
	deploy_image(app, img->lr_up, 0, IMAGE);
	deploy_image(app, img->lr_up, app->xgw - IMAGE, IMAGE);
	deploy_image(app, img->lr_down, 0, app->ygw - (IMAGE * 2));
	deploy_image(app, img->lr_down, app->xgw - IMAGE, app->ygw - (IMAGE * 2));
	deploy_image(app, img->ud_left, IMAGE, 0);
	deploy_image(app, img->ud_left, IMAGE, app->ygw - IMAGE);
	deploy_image(app, img->ud_right, app->xgw - (IMAGE * 2), 0);
	deploy_image(app, img->ud_right, app->xgw - (IMAGE * 2), app->ygw - IMAGE);
}

static void    deploy_borders(t_data *app)
{
	t_walls				*img;
	t_sprites			*addr;
	int x;
	int y;

	img = &(app->wall);
	addr = &(app->path);
	x = IMAGE * 2;
	y = IMAGE * 2;
	deploy_bg(app);
	deploy_corners(app);
	assign_image(app, &(img->side_hor), addr->hor_wall);
	assign_image(app, &(img->side_ver), addr->ver_wall);
	while (x < (app->xgw - IMAGE * 2))
	{
		deploy_image(app, img->side_hor, x, app->ygw - IMAGE);
		deploy_image(app, img->side_hor, x, 0);
		x += IMAGE;
	}
	while (y < (app->ygw - IMAGE * 2))
	{
		deploy_image(app, img->side_ver, 0, y);
		deploy_image(app, img->side_ver, app->xgw - IMAGE, y);
		y += IMAGE;
	}
}

static void	deploy_wall(t_data *app, int j, int i)
{
	t_walls		*img;
	t_sprites	*addr;
	int			x;
	int			y;
	
	img = &(app->wall);
	addr = &(app->path);
	x = (X_BLOCK * j) - (IMAGE * 2);
	y = (Y_BLOCK * i) - IMAGE;
	deploy_image(app, img->ud_left, x, y);
	deploy_image(app, img->side_hor, x + IMAGE, y);
	deploy_image(app, img->ud_right, x + (IMAGE * 2), y);
}

void	deploy_immutable(t_data *app)
{
	int	i;
	int	j;
	int	map_width;

	deploy_borders(app);
	i = 0;
	map_width = ft_strlen(app->map[i]) - 2;
	while (app->map[++i] != NULL)
	{
		j = 0;
		while (app->map[i][++j] != NULL && j < map_width)
		{
			if (app->map[i][j] == '1' && app->map[i + 1] != NULL)
				deploy_wall(app, j, i);
		}
	}
}
