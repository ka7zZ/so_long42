#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void    *mlx_ptr;
	void    *win_ptr;
	int		x, y;
	t_data  img;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		printf("Error\n");
		return (1);
	}
	win_ptr = mlx_new_window(mlx_ptr, 2048, 1080, "Snakeasaurus");
	img.img = mlx_new_image(mlx_ptr, 2048, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 2048)
		{
			my_mlx_pixel_put(&img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);

	mlx_loop(mlx_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}