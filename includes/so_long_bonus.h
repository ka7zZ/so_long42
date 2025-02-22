/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:39:59 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/22 16:30:05 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../import/mlx/mlx.h"
# include "../import/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <limits.h>
# define X_BLOCK	126
# define IMG	42
# define FPS	7000

typedef struct Wall_segment
{
	int	x;
	int	y;
}	t_wseg;

typedef struct Segment
{
	void	*img;
	int		x;
	int		y;
}	t_seg;

typedef struct Animated_paths
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
}	t_animated;

typedef struct Images_paths
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
	char	*bg;
	char	*black;
}	t_image;

typedef struct Walls_box
{
	void	*hor_left;
	void	*hor_right;
	void	*ver_up;
	void	*ver_down;
	void	*corner;
	void	*side_hor;
	void	*side_ver;
	void	*bg;
}	t_wbox;

typedef struct Items_box
{
	t_list	*food;
	t_list	*wseg;
	t_list	*enemies;
	t_list	*gate;
	void	*black;
	int		xpos_gate;
	int		ypos_gate;
	int		finish;
}	t_ibox;

typedef struct s_data
{
	t_wbox		walls;
	t_ibox		items;
	t_list		*snake;
	t_image		path;
	t_animated	anime;
	void		*mlx;
	void		*win_start;
	void		*win_game;
	void		*img_start;
	char		**map;
	char		*map_arg;
	char		*mv;
	char		s_type;
	char		k_pressed;
	int			xlen_win;
	int			ylen_win;
	int			new_x;
	int			new_y;
	int			xpos_snake;
	int			ypos_snake;
	int			xlast_snake;
	int			ylast_snake;
	int			moves;
	int			start;
	int			frames;
}	t_data;

// UTILS
int		ft_assignimg(t_data *app, void **image, char *addr);
int		ft_deployimg(t_data *app, void *image, int x, int y);
// PRINCIPAL
int		ft_glogic(t_data *app);
int		ft_gw(t_data *app);
int		ft_hooks(t_data *app);
void	ft_moves(t_data *app);
// BUIDS
void	ft_gate(t_data *app, int j, int i);
void	ft_immutable(t_data *app);
void	ft_items(t_data *app);
int		ft_deadhead(t_data *app, char type);
int		ft_changeskin(t_data *app);
int		ft_addbody(t_data*app, int x, int y);
// CHECKERS
int		ft_checkbody(t_data *app, int x, int y);
int		ft_checkfood(t_data *app, int x, int y);
void	ft_checkgate(t_data *app, int x, int y);
int		ft_checkwall(t_data *app, int x, int y);
int		ft_checkenemy(t_data *app, int x, int y);
// FREES
int		ft_freegame(t_data *app);
int		ft_freeitems(t_data *app);
int		ft_freestart(t_data *app);
// MAP
int		ft_buildmap(t_data *app, char *argv);
int		ft_checkmap(t_data *app, char *argv);
int		ft_freemap(char **map);
int		ft_errormap(t_data *app);
// main
int		main(int argc, char **argv);
#endif