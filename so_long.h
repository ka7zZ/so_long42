/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:39:59 by aghergut          #+#    #+#             */
/*   Updated: 2025/01/15 16:20:03 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	void	*img;
	int		x;
	int		y;
}	t_enemy;

typedef struct Gate_segment
{
	void	*img;
	int		x;
	int		y;
}	t_gate;

typedef struct	Animated_paths
{
	char	*enemy0;
	char	*enemy1;
	char	*enemy2;
	char	*enemy3;
	char	*enemy4;
	char	*gate0;
	char	*gate1;
	char	*gate2;
	char	*gate3;
	char	*gate4;
	char	*gate5;
	char	*gate6;
}	t_animated;

typedef struct	Sprites_paths
{
	char	*egg;
	char	*apple;
	char	*enemy;
	char	*snake_ghead;
	char	*snake_gdhead;
	char	*snake_gbody;
	char	*snake_yhead;
	char	*snake_ydhead;
	char	*snake_ybody;
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
	t_list	*gate;
	void	*black;
	int		xgate;
	int		ygate;
	int		finish;
}	t_ibox;

typedef struct	s_data {
	t_wbox		walls;
	t_ibox		items;
	t_list		*snake;
	t_sprites	path;
	t_animated	anime;
	void		*mlx;
	void		*win_start;
	void		*win_game;
	void		*img_start;
	char    	**map;
	char		*map_arg;
	char		*mv_str;
	char		s_type;
	int			xgw;
	int			ygw;
	int			sx_pos;
	int			sy_pos;
	int			sx_last;
	int			sy_last;
	int			w_press;
	int			a_press;
	int			s_press;
	int			d_press;
	int			moves;
	int			start;
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