#ifndef SO_LONG_H
#   define SO_LONG_H

// include own folder's libs
#include "mlx/mlx.h"
#include "lib42/libft.h"
#include <X11/keysym.h>
// #include "ingame/ingame.h"
// #include "mapping/mapping.h"
// #include "checker/checker.h"

// include SYS libs
// #include <X11/keysym.h>

# define BLOCK  126
# define IMAGE  42

//	WALL, COLLECTIBLES, ENEMY, PLAYER, EXIT ADDRESES
typedef	struct Map_wall_addr
{
	char	*corner;
	char	*hor_left;
	char	*hor_right;
	char	*hor_wall;
	char	*ver_up;
	char	*ver_down;
	char	*ver_wall;
	char    *bg;
}	t_map_walls_addr;

typedef	struct Map_fesg_addr
{
	char	*egg;
	char	*apple;
	char	*enemy;
	char	*snake_head;
	char	*snake_body;
	char	*snake_hdead;
	char	*snake_bdead;
	char	*exit_gate;
	char	*start_gate;
}	t_map_fesg_addr;

typedef struct	Sprites_addr
{
	t_map_walls_addr	walls;
	t_map_fesg_addr		fesg;
}	t_sprites;

// (INGAME) SNAKE

typedef struct	Snake {
	void	*head;
	t_list	*body;
	int		xh_pos;
	int		yh_pos;
	int		xb_pos;
	int		yb_pos;
}   t_snake;

// (INGAME) MAP

typedef struct Map_walls
{
	void	*ud_left;
	void	*ud_right;
	void	*lr_up;
	void	*lr_down;
	void	*corner;
	void	*side_hor;
	void    *side_ver;
	void    *bg;
}   t_walls;

typedef struct Map_items
{
	void	*food;
	void	*exit_gate;
	void	*start_gate;
	void	*enemy;
	int		xeg;
	int		yeg;
}	t_items;

typedef struct Map_construct
{
	t_walls		wall;
	t_items		item;
	t_snake		s;
	t_sprites	spr;
}   t_map;

// (DATAS)
typedef struct	s_data {
	t_map   *game;
	void	*mlx;
	void	*win1;
	void    *win2;
	void	*imgw1;
	void	*imgw2;
	char	*addr_w2;
	int		bpp;
	int		line;
	int		endian;
	char    **map;
	int		xw2;
	int		yw2;
}   t_data;

void    hooks(t_data *app);
void	destroy_game(t_data *app);
// void    put_borders(t_data *app);
// void    put_background(t_data *app);
void	deploy_immutable(t_data *app);
void	initalize_data(t_data *ptr);
void	wall_init(t_data *app);
void	fseg_init(t_data *app);
void	init_win1(t_data *app);
void    deploy_image(t_data *app, void *image, int x, int y);
void    assign_image(t_data *app, void **image, char *addr);
void	deploy_items(t_data *app);
void	game_window(t_data *app);

#endif