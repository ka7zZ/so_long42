#ifndef SO_LONG_H
#   define SO_LONG_H

#include "import/mlx/mlx.h"
#include "import/libft/libft.h"
#include <X11/keysym.h>
#include <X11/X.h>

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

typedef struct Walls_box
{
	void	*hor_left;
	void	*hor_right;
	void	*ver_up;
	void	*ver_down;
	void	*corner;
	void	*side_hor;
	void    *side_ver;
	void    *bg;
}   t_wbox;

typedef struct Items_box
{
	t_list	*food;
	t_list	*wseg;
	t_list	*enemies;
	void	*exit_gate;
	void	*start_gate;
	void	*black;
	int		xsg;
	int		ysg;
}	t_ibox;

typedef struct	s_data {
	t_wbox		walls;
	t_ibox		items;
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

// include own folder's libs

#include "check_map/checker.h"
#include "ingame/ingame.h"
#include "builds/builds.h"

# define X_BLOCK	126
# define IMAGE	42


int		free_start(t_data *app);
int     main(int argc, char **argv);
#endif