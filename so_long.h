/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:39:59 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/05 15:29:53 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "import/mlx/mlx.h"
# include "import/libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <limits.h>
# include "create_map/create_map.h"
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

// frees subfolder
int		free_start(t_data *app);
int		free_game(t_data *app);
int		free_items(t_data *app);

//ingame subfolder
void	check_gate(t_data *app, int x, int y);
int		check_wall(t_data *app, int x, int y);
int		check_food(t_data *app, int x, int y);
int		check_body(t_data *app, int x, int y);
int		check_enemy(t_data *app, int x, int y);
void	count_moves(t_data *app);
int		game_logic(t_data *app);
int		game_window(t_data *app);
int		hooks(t_data *app);

//builds subfolder
int		assign_image(t_data *app, void **image, char *addr);
int		deploy_image(t_data *app, void *image, int x, int y);
void	deploy_immutable(t_data *app);
void	deploy_items(t_data *app);
void	deploy_gate(t_data *app, int j, int i);

// void	deploy_enemy_anim(t_data *app, int j, int i);
int		add_body(t_data*app, int x, int y);
int		dead_head(t_data *app, char type);
int		change_skin(t_data *app);

// main
int		main(int argc, char **argv);

#endif