
#include "so_long.h"

static void	deploy_fe(t_data *app, char c, int j, int i)
{
	t_items				*img;
	t_map_fesg_addr		*addr;
	int					x;
	int					y;
	static int			n_food = 0;

	img = &(app->game->item);
	addr = &(app->game->spr.fesg);
	x = (BLOCK * j) - IMAGE;
	y = (BLOCK * i) - IMAGE;
	if (c == 'C')
	{
		n_food++;
		if (n_food % 2 == 0)
			assign_image(app, &(img->food), addr->egg);
		else 
			assign_image(app, &(img->food), addr->apple);
		deploy_image(app, img->food, x, y);
	}
	if (c == 'E')
	{
		assign_image(app, &(img->start_gate), addr->start_gate);
		img->xeg = x;
		img->yeg = y;
		deploy_image(app, img->start_gate, img->xeg, img->yeg);
	}
}

static void	deploy_wall(t_data *app, char c, int j, int i)
{
	t_walls				*img;
	t_map_walls_addr	*addr;
	int					x;
	int					y;
	
	img = &(app->game->wall);
	addr = &(app->game->spr.walls);
	x = (BLOCK * j) - IMAGE;
	y = (BLOCK * i) - IMAGE;
	if (c == '1')
	{
		assign_image(app, &(img->ud_left), addr->hor_left);
		assign_image(app, &(img->side_hor), addr->hor_wall);
		assign_image(app, &(img->ud_right), addr->hor_right);
		deploy_image(app, img->ud_left, x, y);
		deploy_image(app, img->side_hor, x + IMAGE, y);
		deploy_image(app, img->ud_right, x + (IMAGE * 2), y);
	}

}

static void deploy_snake(t_data *app, char c, int j, int i)
{
	
	t_snake				*img_s;
	t_list				*tail;
	t_list				*ptr;
	t_map_fesg_addr		*addr;
	static int			count_tlist = 0;

	if (c == 'P')
	{
		img_s = &(app->game->s);
		addr = &(app->game->spr.fesg);
		img_s->body = ft_lstnew(NULL);
		img_s->xh_pos = (BLOCK * j) - IMAGE;
		img_s->yh_pos = (BLOCK * i) - IMAGE;
		assign_image(app, &(img_s->head), addr->snake_head);
		tail = ft_lstnew(NULL);
		assign_image(app, &(tail->content), addr->snake_body);
		ft_lstadd_back(&(img_s->body), ft_lstnew(tail->content));
		deploy_image(app, img_s->head, img_s->xh_pos, img_s->yh_pos);
		img_s->xb_pos = img_s->xh_pos + IMAGE;
		img_s->yb_pos = img_s->yh_pos;
		ptr = img_s->body;
		while (ptr != NULL)
		{
			deploy_image(app, tail->content, img_s->xb_pos, img_s->yb_pos);
			img_s->xb_pos += IMAGE;
			ptr = ptr->next;
		}
		free(tail->content);
		free(tail);
	}
}

void	deploy_items(t_data *app)
{
	int					i;
	int					j;
	int					map_width;
	t_map				items;

	app->game = &items;
	fseg_init(app);
	wall_init(app);
	i = 0;
	map_width = ft_strlen(app->map[0]) - 1;
	while(app->map[++i] != NULL)
	{
		if (app->map[i + 1] == NULL)
			break;
		j = 0;
		while (app->map[i][++j] != '\0' && j < map_width - 1)
		{
			deploy_fe(app, app->map[i][j], j, i);
			deploy_wall(app, app->map[i][j], j, i);
			deploy_snake(app, app->map[i][j], j, i);
		}		
	}
}