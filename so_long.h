#ifndef SO_LONG_H
#   define SO_LONG_H

// include own folder's libs
#include "mlx/mlx.h"
#include "lib42/libft.h"
#include <X11/keysym.h>
#include <X11/X.h>
// #include "ingame/ingame.h"
// #include "mapping/mapping.h"
// #include "checker/checker.h"

// include SYS libs
// #include <X11/keysym.h>
# define X_BLOCK	126
# define Y_BLOCK	84
# define IMAGE	42

//	WALL, COLLECTIBLES, ENEMY, PLAYER, EXIT ADDRESES

typedef struct	Sprites_paths
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
	char	*corner;
	char	*hor_left;
	char	*hor_right;
	char	*hor_wall;
	char	*ver_up;
	char	*ver_down;
	char	*ver_wall;
	char    *bg;
	char	*black;
}	t_sprites;

// (INGAME) SNAKE

typedef struct	Snake {
	void	*head;
	t_list	*body;
	int		x;
	int		y;
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
	t_list	*food;
	void	*exit_gate;
	void	*start_gate;
	void	*enemy;
	void	*black;
	int		xeg;
	int		yeg;
}	t_items;

// (DATAS)
typedef struct	s_data {
	t_walls		wall;
	t_items		item;
	t_snake		snake;
	t_sprites	path;
	void		*mlx;
	void		*win_start;
	void		*win_game;
	void		*img_start;
	char    	**map;
	char		*mv_str;
	int			xgw;
	int			ygw;
	int			start;
	int			moves;
}   t_data;

typedef struct Body_segment
{
	void	*img;
	int		x;
	int		y;
}	t_body;

typedef struct Food_segment
{
	void	*img;
	int		x;
	int		y;
}	t_food;

void    start_hooks(t_data *app);
void	deploy_immutable(t_data *app);
void	deploy_items(t_data *app);
void    deploy_image(t_data *app, void *image, int x, int y);
void    assign_image(t_data *app, void **image, char *addr);
void	game_hooks(t_data *app);
void	game_window(t_data *app);
int		free_start(t_data *app);
int		free_game(t_data *app);
void	checker(t_data *app, char *argv);

#endif