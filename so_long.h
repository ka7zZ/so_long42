#ifndef SO_LONG_H
#   define SO_LONG_H

// include own folder's libs
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "ingame/ingame.h"
#include "mapping/mapping.h"

// include SYS libs
#include <X11/keysym.h>

# define BLOCK  42

// (DATAS)
typedef struct	s_data {
	void	*mlx;
	void	*win1;
    void    *win2
	void	*imgw1;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}   t_data;

// (INGAME) SNAKE

typedef struct Snake_body
{
	void	*body;
	int		x_pos;
	int		y_pos;
	struct Snake_body	*next;
}	t_sbody;

struct	Snake {
	void	*head;
	void	*tail;
	t_sbody	*ptr;
	int		xh_pos;
	int		yh_pos;
	int		xt_pos;	
	int 	yt_pos;
};

// (INGAME) MAP

struct Map_elbows
{
	void	*uleft_corner;
	void	*uright_corner;
	void	*dleft_corner;
	void	*dright_corner;
	int		xul_pos;
	int		yul_pos;
	int		xur_pos;
	int		yur_pos;
	int		xdl_pos;
	int		ydl_pos;
	int		xdr_pos;
	int		ydr_pos;
};

struct Map_outline
{
	t_map_elbows	*ptr_top;
	t_map_elbows	*ptr_low;
	void			*corner;
	void			*sides;
	int				*xc_pos;
	int				*yc_pos;
	int				*xs_pos;
	int				*ys_pos;
};

typedef struct Map_food
{
	void			*food;
	int				x_pos;
	int				y_pos;
	struct Map_food	*next;
}	tmap_food;

struct Map_exit
{
	void	*exit_gate;
	int		x_pos;
	int		y_pos;
};

typedef struct Map_enemy
{
	void				*enemy;
	int					x_pos;
	int					y_pos;
	struct Map_enemy	*next;
}	tmap_enemy;

struct Map_construct
{
    Map_outline *m;
    tmap_food   *f;
    tmap_enemy  *e;
    Map_exit    *g;
    Snake       *s;
};
#endif