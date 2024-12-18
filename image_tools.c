#include "so_long.h"

void    assign_image(t_data *app, void **image, char *addr)
{
	int width;
	int height;

    if (addr == NULL)
    {
        ft_printf("addr nulled");
        exit(0);
    }
    width = IMAGE;
	height = IMAGE;
	*image = mlx_xpm_file_to_image(app->mlx, addr, &width, &height);
	if (!(*image))
		destroy_game(app);
}

void    deploy_image(t_data *app, void *image, int x, int y)
{
	mlx_put_image_to_window(app->mlx, app->win2, image, x, y);
}
