/*PARSE MAP old func
-----------------------------------------------------------------------
void	parse_map(t_data *app, t_map_construct	*game)
{
	int	i;
	int	j;
	int	pos;
	i = -1;
	pos = 0;
	while (app->map[++i] != NULL)
	{
		j = -1;
		while (app->map[i][++j] != NULL)
		{
			if (app->map[i][++j] == 'C')
		}
	}
}

void	put_map(t_data *app, int x, int y)
{
}

void	construct_elbows(t_data *app, t_map *item)
{
	t_sprites	addr;
	int			hor_walls;
	int			ver_walls;
	int			idx;
	hor_walls = ft_strlen(app->map[0]);
	ver_walls = 0;
	idx = -1;
	while (app->map[++idx] != NULL)
		ver_walls++;
	sprites_addr_init(&addr);
	item->m->corner = mlx_xpm_file_to_image(app->mlx, 
											addr.walls.corner,
											42, 42);
}
PUT ON THE WINDOW FUNC
-----------------------------------------------------------------------


*/

