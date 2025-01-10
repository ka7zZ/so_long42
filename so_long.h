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
# define X_BLOCK	126 // size of snake
# define IMAGE	42 //pixels of images

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

// (INGAME) MAP

typedef struct Map_walls
{
	void	*hor_left;
	void	*hor_right;
	void	*ver_up;
	void	*ver_down;
	void	*corner;
	void	*side_hor;
	void    *side_ver;
	void    *bg;
}   t_walls;

typedef struct Map_items
{
	t_list	*food;
	t_list	*wseg;
	t_list	*enemies;
	void	*exit_gate;
	void	*start_gate;
	void	*black;
	int		xsg;
	int		ysg;
}	t_items;

// (DATAS)
typedef struct	s_data {
	t_walls		walls;
	t_items		items;
	t_list		*snake;
	t_sprites	path;
	void		*mlx;
	void		*win_start;
	void		*win_game;
	void		*img_start;
	char    	**map;
	char		*mv_str;
	int			xgw;
	int			ygw;
	int			sx_pos;
	int			sy_pos;
	int			sx_last;
	int			sy_last;
	int			start;
	int			moves;
}   t_data;

typedef struct Snake_segment
{
	void	*img;
	int		x;
	int		y;
}	t_snake;

typedef struct Food_segment
{
	void	*img;
	int		x;
	int		y;
}	t_food;

typedef struct Wall_segment
{
	int	x;
	int	y;
}	t_wseg;

typedef struct Enemy_segment
{
	int		x;
	int		y;
}	t_enemy;

// frees
void	free_immutable(t_data *app);
void	free_enemies(t_data *app);
void	free_collectibles(t_data *app);
void	free_snake(t_data *app);
void	free_wallseg(t_data	*app);
int		free_start(t_data *app);
int		free_game(t_data *app);

void    start_hooks(t_data *app);
void    deploy_image(t_data *app, void *image, int x, int y);
void    assign_image(t_data *app, void **image, char *addr);
void	deploy_immutable(t_data *app);
void	deploy_map(t_data *app);
void	game_hooks(t_data *app);
void	game_window(t_data *app);

void	add_body(t_data*app, int x, int y);
void	checker(t_data *app, char *argv);
int		check_body(t_data *app, int new_x, int new_y);
void	action(t_data *app, int new_x, int new_y);

#endif