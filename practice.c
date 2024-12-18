
/* Functions of mlx categorized
*****
*****

1. Initializing and base resources
	
	-> mlx_init() : Initializes the connection to the X server 	(Parameter: void) 																				(Return: void *mlx_ptr);
	-> mlx_new_window() : Creates a new window					(Parameters: void *mlx_ptr, int width, int height, char *title)									(Return: void *win_ptr);

2. Manipulating workspace
	
	-> mlx_clear_window() : Cleans the window's content			(Parameters: void *mlx_ptr, void *win_ptr)														(Return: int);
	-> mlx_pixel_put() : Drawing pixels on the window			(Parameters: void *mlx_ptr, void *win_ptr, int widht, int height, int color)					(Return: int);
	-> mlx_destroy_window() : Destroys the window				(Parameters: void *mlx_ptr, void *win_ptr)														(Return: int);

3. Handling images
	
	-> mlx_new_image() : Creates a new image					(Parameters: void *mlx_ptr, int width, int height)												(Return: void *img_ptr);
	-> mlx_get_data_addr() : Returns the address of the image	(Parameters: void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)					(Return: char *);
	-> mlx_get_color_value() : Returns the color value			(Parameters: void *mlx_ptr, int color)															(Return: int);
	-> mlx_put_image_to_window() : Puts the image on the window	(Parameters: void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)							(Return: int);
	-> mlx_destroy_image() : Destroys the image					(Parameters: void *mlx_ptr, void *img_ptr)														(Return: int);

4. Event and input functions

	-> mlx_hook() : Hooks the event to the window				(Parameters: void *win_ptr, int ev_type, int ev_msk, int (*funct_ptr)(), void *param)			(Return: int);
	-> mlx_mouse_hook() : Hooks the mouse event to the window	(Parameters: void *win_ptr, int (*funct_ptr)(), void *param)									(Return: int);
	-> mlx_key_hook() : Hooks the key event to the window		(Parameters: void *win_ptr, int (*funct_ptr)(), void *param)									(Return: int);
	-> mlx_expose_hook() : Hooks the expose event to the window	(Parameters: void *win_ptr, int (*funct_ptr)(), void *param)									(Return: int);

5. Text and pixel rendering
	
	-> mlx_string_put() : Puts the string on the window			(Params: void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)					(Return: int);
	-> mlx_set_font() : Sets the font for the window			(Parameters: void *mlx_ptr, void *win_ptr, char *name)											(Return: void);
	-> mlx_xpm_to_image(): Converts XPM data to image			(Parameters: void *mlx_ptr, char **xpm_data, int *width, int *height)							(Return: void *);
	-> mlx_xpm_file_to_image() : Converts XPM file to image		(Parameters: void *mlx_ptr, char *filename, int *width, int *height)							(Return: void *);

6. Display management

	-> mlx_flush() : Flushes the display						(Parameters: void *mlx_ptr)																		(Return: void);
	-> mlx_sync : Syncs the display								(Parameters: void *mlx_ptr)																		(Return: int);
	-> mlx_sync_wait() : Waits for the sync						(Parameters: void *mlx_ptr)																		(Return: int);
	-> mlx_destroy_display() : Destroys the display				(Parameters: void *mlx_ptr)																		(Return: int);

	
7. Helper functions for managing loops and events

	-> mlx_do_key_autorepeat_off() : Disables the key autorepeat(Parameter: void)																				(Return: void);
	-> mlx_do_key_autorepeat_on() : Enables the key autorepeat	(Parameter: void)																				(Return: void);
	-> mlx_loop() : Starts the event loop						(Parameter: void *mlx_ptr)																		(Return: int);
	-> mlx_loop_end() : Ends the event loop						(Parameter: void *mlx_ptr)																		(Return: int);
	-> mlx_loop_hook() : Hooks the loop event					(Parameters: void *mlx_ptr, int (*funct_ptr)(), void *param)									(Return: int);
******
******
*/

/*	X11 server key codes
# 
#
sdl x11
sdl dga
9	53	# Esc
67	122	# F1
68	120	# F2
69	99	# F3
70	118	# F4
71	96	# F5
72	97	# F6
73	98	# F7
74	100	# F8
75	101	# F9
76	109	# F10
95	103	# F11
96	127	# F12
111	105	# PrintScrn
78	107	# Scroll Lock
110	113	# Pause
49	50	# `
10	18	# 1
11	19	# 2
12	20	# 3
13	21	# 4
14	23	# 5
15	22	# 6
16	26	# 7
17	28	# 8
18	25	# 9
19	29	# 0
20	27	# -
21	24	# =
22	51	# Backspace
106	114	# Insert
97	115	# Home
99	116	# Page Up
77	71	# Num Lock
112	75	# KP /
63	67	# KP *
82	78	# KP -
23	48	# Tab
24	12	# Q
25	13	# W
26	14	# E
27	15	# R
28	17	# T
29	16	# Y
30	32	# U
31	34	# I
32	31	# O
33	35	# P
34	33	# [
35	30	# ]
36	36	# Return
107	117	# Delete
103	119	# End
105	121	# Page Down
79	89	# KP 7
80	91	# KP 8
81	92	# KP 9
86	69	# KP +
66	57	# Caps Lock
38	0	# A
39	1	# S
40	2	# D
41	3	# F
42	5	# G
43	4	# H
44	38	# J
45	40	# K
46	37	# L
47	41	# ;
48	39	# '
83	86	# KP 4
84	87	# KP 5
85	88	# KP 6
50	56	# Shift Left
94	50	# International
52	6	# Z
53	7	# X
54	8	# C
55	9	# V
56	11	# B
57	45	# N
58	46	# M
59	43	# ,
60	47	# .
61	44	# /
62	56	# Shift Right
51	42	# \
98	62	# Cursor Up
87	83	# KP 1
88	84	# KP 2
89	85	# KP 3
108	76	# KP Enter
37	54	# Ctrl Left
115	58	# Logo Left (-> Option)
64	55	# Alt Left (-> Command)
65	49	# Space
113	55	# Alt Right (-> Command)
116	58	# Logo Right (-> Option)
117	50	# Menu (-> International)
109	54	# Ctrl Right
100	59	# Cursor Left
104	61	# Cursor Down
102	60	# Cursor Right
90	82	# KP 0
91	65	# KP .
*/

/* fonts mlx 
* 5x7
* 10x13
* 10x20
* 12x13

*/

/* CHECKERS
#include "libft/libft.h"
#   define BUFFER_SZ 1024
void    free_map(char ***map)
{
   int i;

	if (!map || !*map)
		return;
	i = 0;
	while((*map)[i] != NULL)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL; 
}

static void return_error(char	***map)
{
	free_map(map);
	ft_printf("Wrong format of the map!\n");
	exit(EXIT_FAILURE);
}

static int	count_lines(char *argv)
{
	int		fd;
	int		count;
	int		bytes;
	int		i;
	char	buffer[BUFFER_SZ];

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes = read(fd, buffer, BUFFER_SZ);
	if (bytes < 0)
		return (close(fd), 0);
	buffer[bytes] = '\0';
	i = 0;
	count = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	close(fd);
	return (++count);
}

static int	check_wall(char **map, int last_row)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		len = ft_strlen(map[i]);
		if (ft_strchr(map[i], '\n'))
			len -= 2; // -1 for \n, -1 for the last 1. This variable is for comprobation of the else if
		if (map[i][++j] != '1')
			return_error(&map);
		while (map[i][++j] != '\n' && map[i][j] != '\0')
		{
			
			if ((i == 0 || i == last_row) && map[i][j] != '1')
				return_error(&map);
			else if ((i > 0 == i < last_row) && j < len && map[i][j] == '1')
				return_error(&map);
		}
		if (map[i][--j] != '1')
			return_error(&map);
	}
	return (1);
}

static int	check_format(char **map)
{
	int 	i;
	int		len;
	int		test;

	i = -1;
	while (map[++i] != NULL)
	{
		if (i == 0)
			len = ft_strlen(map[i]);
		else
		{
			test = ft_strlen(map[i]);
			if (!ft_strchr(map[i], '\n'))
				len -= 1;		// -1 because of the char new line at the end of the string
			if (len != test)
				return_error(&map);
		}
	}
	if (test == i)
		return_error(&map);
	if (check_wall(map, --i)) // --i for the last row of the map
		return (1);
	return (0);
}

static char	**read_map(char *argv)
{
	char	**map;
	int		fd;
	int		lines;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error reading the map!\n", 23);
		exit(EXIT_FAILURE);
	}
	lines = count_lines(argv);
	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (close(fd), NULL);
	i = -1;
	while (++i < lines)
		map[i] = get_next_line(fd);
	map[i] = NULL;
	return (map);
}

char	**check_map(char *argv)
{
	char    **map;
	int     i;
	int     j;

	map = read_map(argv);
	if (!map)
		return_error(&map);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (!ft_strchr("01EPC", map[i][j]))
				return_error(&map);
			j++;                
		}
		i++;
	}
	if (check_format(map))
		return (map);
	return (NULL);
}

void	check_symbol(char **map)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (map[++i] != NULL)
	{
		j = 0;
		while (map[i][++j] != NULL)
		{
			if (map[i][j] == 'P')
				s++;
		}
	}
	if (s != 1)
		return_error(&map);	
}

void	check_space(char **map)
{
	int	i;
	int	j;
	int err;

	i = 0;
	err = 1;
	while (map[++i] != NULL)
	{
		j = 0;
		while (map[i][++j] != NULL)
		{
			if (map[i][j] == 'P' &&\
			map[i][j - 1] == '0' && map[i][j + 1] == '0' )
				err = 0;
			else if (map[i][j] == 'P' &&\	
			map[i + 1][j] == '0' && map[i - 1][j] == '0')
				err = 0;
		}
	}
	if (err)
		return_error(&map);
}

void    check_snake(char  **map)
{
	check_symbol(map);
	check_space(map);
}

void	check_exit(char **map)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (map[++i] != NULL)
	{
		j = 0;
		while (map[i][++j] != NULL)
		{
			if (map[i][j] == 'E')
				s++;
		}
	}
	if (s != 1)
		return_error(&map);	
}

*/

/* fonts, putstrings, secondwindow, hooks
	// Define exit buttons
	

	// set FONT of all the writtings of the window
	mlx_set_font(mlx, app.win_ptr, "10x20");
	// put a text into window at the precise position
	win_str = "Welcome to Snakeasaurus game!";
	mlx_string_put(mlx, app.win_ptr, ((2048 - 800)/2) + 250, ((1080 - 600)/2) - 50, 0x00FFFFFF, win_str);
	
	// setting second_window_position's values
	second_window_position(&s_board);

	mlx_string_put(mlx, app.win_ptr, s_board.x_pos, s_board.y_pos, 0x00FF0000, s_board.name);

	mlx_mouse_hook(app.win_ptr, handle_scoreboard, &s_board);
*/

/* img addr + draw a background
	app.addr = mlx_get_data_addr(app.img, &app.bits_per_pixel, &app.line_length, &app.endian);
	background_posx = (2000 - 800)/2;
	background_posy = (1000 - 600)/2;

	// draw the size of the image pixel by pixel where y = height and x = width
	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			my_mlx_pixel_put(&app, x, y, 0xFF123456);
			x++;
		}
		y++;
	}
*/

/* Rest of variables
	// int		background_posx;
	// int		background_posy;
	// int		head_posx;
	// int		head_posy;
	// int		x;
	// int		y;
	// char	*win_str;
*/

/* rest of the practice
typedef struct	Snake {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_pos;
	int		y_pos;
}	t_snake;

void print_pixels(int * pixels) {
	int i = 0;

	while (i < 50 * 10) 
	{
		int pixel_color = pixels[i]; 

		int alpha = (pixel_color >> 24) & 0xFF; 
		int red   = (pixel_color >> 16) & 0xFF; 
		int green = (pixel_color >> 8) & 0xFF;  
		int blue  = pixel_color & 0xFF;

		printf("Pixel %d: (A: %d, R: %d, G: %d, B: %d)\n", i, alpha, red, green, blue);

		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	second_window_position(t_score *s_ptr)
{
	s_ptr->name = "Play the game";
	s_ptr->x_pos = ((2048 - 800)/2) - 350;
	s_ptr->y_pos = ((1080 - 600)/2) + 50;
	s_ptr->width_name = strlen(s_ptr->name) * 20;
	s_ptr->height_lttr = 20;
}

int		scoreboard_close(int keycode, void *param)
{	
	mlx_destroy_window(mlx, s_win);
	return (0);

}

int		move_image(int keycode, void *param)
{
	if (keycode == XK_a)    // A key (move left)
	{    
		if (sx_pos <= 0)
			return 0;
		sx_pos -= 10;
		printf("A KEY x_pos: %d\n", sx_pos);
	}
	if (keycode == XK_d)    // D key (move right)
	{
		if (sx_pos >= 200)
			return 0;
		sx_pos += 10;
		printf("D KEY x_pos: %d\n", sx_pos);
	}
	if (keycode == XK_w)   // W key (move up)
	{
		if (sy_pos <= 0)
			return 0;
		sy_pos -= 10;
		printf("W KEY y_pos: %d\n", sy_pos);
	}
	if (keycode == XK_s)    // S key (move down)
	{
		if (sy_pos >= 110)
			return 0;
		sy_pos += 10;
		printf("S KEY y_pos: %d\n", sy_pos);
	}
	mlx_clear_window(mlx, s_win); // Clear the window
	mlx_put_image_to_window(mlx, s_win, img_border, sx_pos, sy_pos); // Redraw the image at the new position

	return 0;
}

int		handle_scoreboard(int button, int x, int y, t_score *s_ptr)
{
	// defining the image size
	int	img_width = 98;
	int	img_height = 98;
	int *pixels;
	int	x_img;
	int	y_img;


	if (s_ptr == NULL)
		return (0);
	if (button == 1)
	{
		// defining the space of the window where to click to open the window
		if (x >= s_ptr->x_pos && x <= s_ptr->x_pos + s_ptr->width_name && \
				y >= s_ptr->y_pos && y <= s_ptr->y_pos + s_ptr->height_lttr)
		{
			// defining the second window
			s_win = mlx_new_window(mlx, 980, 980, "Be the best player!");
			if (!s_win)
			{
				mlx_destroy_display(mlx);
				retu	t_data			data;
rn (1);
			}
			// defining the image that will appear in the second window -->> !!! the image should be with "./"
			img_border = mlx_xpm_file_to_image(mlx, "./assets/pngs/corner.xpm", &img_width, &img_height);
			if (img_border == NULL) {
				printf("Error loading image.\n");
				// exit(1);
			}
			//pixels = mlx_get_data_addr(img_border, &img_width, &img_height, &img_height);
			x_img = 0;
			while(x_img <= 980)
			{
				y_img = 0;
				mlx_put_image_to_window(mlx, s_win, img_border, x_img, y_img);
				y_img = 882;
				mlx_put_image_to_window(mlx, s_win, img_border, x_img, y_img);
				x_img += img_width;
			}
			y_img = 98;
			while (y_img <= 980)
			{
				x_img = 0;
				mlx_put_image_to_window(mlx, s_win, img_border, x_img, y_img);
				x_img =  882;
				mlx_put_image_to_window(mlx, s_win, img_border, x_img, y_img);
				y_img += img_height;
			}
			// print_pixels(pixels);
			// printf("pixels: %d\n", pixels);
			// put the image to the window at the center of it
			// mlx_put_image_to_window(mlx, s_win, img, sy_pos, sx_pos);
			// define the "X" button to close the window
			mlx_hook(s_win, 17, 0, scoreboard_close, NULL);
			//mlx_key_hook(s_win, move_image, NULL);
		}
	}
	return (0);
}
*/

/* FIRST SCRIPT WORKS
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "checkers/checkers.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <math.h>

// INIT T_DATA
void	initalize_data(t_data *ptr)
{
	ptr->mlx = NULL;
	ptr->win1 = NULL;
	ptr->win2 = NULL;
	ptr->imgw1 = NULL;
	ptr->map = NULL;
}

void	wall_init(t_map_walls_addr *ptr)
{
	(*ptr).corner = ft_strdup("assets/xpm/corner.xpm");
	(*ptr).hor_left = ft_strdup("assets/xpm/hor_left.xpm");
	(*ptr).hor_wall = ft_strdup("assets/xpm/hor_wall");
	(*ptr).hor_right = ft_strdup("assets/xpm/hor_right.xpm");
	(*ptr).ver_up = ft_strdup("assets/xpm/ver_up.xpm");
	(*ptr).ver_down = ft_strdup("assets/xpm/ver_down.xpm");
	(*ptr).ver_wall = ft_strdup("assets/xpm/ver_wall.xpm");
}

void	fseg_init(t_map_fesg_addr *ptr)
{
	(*ptr).food = ft_strdup("assets/xpm/egg.xpm");
	(*ptr).enemy = ft_strdup("assets/xpm/enemy.xpm");
	(*ptr).gate = ft_strdup("assets/xpm/gate.xpm");
	(*ptr).snake_bdead = ft_strdup("assets/xpm/snake_bdead.xpm");
	(*ptr).snake_body = ft_strdup("assets/xpm/snake_body.xpm");
	(*ptr).snake_hdead = ft_strdup("assets/xpm/snake_hdead.xpm");
	(*ptr).snake_head = ft_strdup("assets/xpm/snake_head.xpm");
}

void	sprites_addr_init(t_sprites *ptr)
{
	wall_init(&(*ptr).walls);
	fseg_init(&(*ptr).fesg);
}

// DESTROY FUNCTION
void	destroy_game(t_data *app)
{
	write(1, "Destroying the game!\n", 21);
	if (app->map)
		free_map(&app->map);
	if (app->imgw1)
		mlx_destroy_image(app->mlx, app->imgw1);
	if (app->win1)
		mlx_destroy_window(app->mlx, app->win1);
	if (app->win2)
		mlx_destroy_window(app->mlx, app->win2);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
		app->mlx = NULL;
	}
	exit(0);
}

// --------------     WINDOWS 2 -----------------


void	create_wall(t_data *app, t_map **game)
{
	int width;
	int height;

	width = 42;
	height = 42;
	app->xw2 -= width;
	app->yw2 -= height;
	(*game)->wall.corner = mlx_xpm_file_to_image(app->mlx, (*game)->spr.walls.corner, &width, &height);
	if (!(*game)->wall.corner)
		destroy_game(app);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.corner, 0, 0);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.corner, 0, app->yw2);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.corner, app->xw2, 0);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.corner, app->xw2, app->yw2);
	(*game)->wall.lr_up = mlx_xpm_file_to_image(app->mlx, (*game)->spr.walls.ver_up, &width, &height);
	if (!(*game)->wall.lr_up)
		destroy_game(app);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.lr_up, 0, height);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.lr_up, app->xw2, height);
	(*game)->wall.lr_down = mlx_xpm_file_to_image(app->mlx, (*game)->spr.walls.ver_down, &width, &height);
	if (!(*game)->wall.lr_down)
		destroy_game(app);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.lr_down, 0, app->yw2 - height);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.lr_down, app->xw2, app->yw2 - height);
	(*game)->wall.ud_left = mlx_xpm_file_to_image(app->mlx, (*game)->spr.walls.hor_left, &width, &height);
	if (!(*game)->wall.ud_left)
		destroy_game(app);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.ud_left, width, 0);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.ud_left, width, app->yw2);
	(*game)->wall.ud_right = mlx_xpm_file_to_image(app->mlx, (*game)->spr.walls.hor_right, &width, &height);
	if (!(*game)->wall.ud_right)
		destroy_game(app);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.ud_right, app->xw2 - width, 0);
	mlx_put_image_to_window(app->mlx, app->win2, (*game)->wall.ud_right, app->xw2 - width, app->yw2);
}


void	game_window(t_data *app)
{
	int	i;
	t_map	*game;


	i = 0;
	while(app->map[i] != NULL)
		i++;
	app->xw2 = (ft_strlen(app->map[i - 1])) * BLOCK;
	app->yw2 = (i - 1) * BLOCK;
	app->win2 = mlx_new_window(app->mlx, app->xw2, app->yw2, "The journey");
	if (!app->win2)
		destroy_game(app);
	game = malloc(sizeof(t_map));
	sprites_addr_init(&game->spr);
	//ft_printf("spritees:\n%s\n%s\n%s\n%s\n", game.spr.walls.hor_left, game.spr.walls.hor_right, game.spr.fesg.enemy, game.spr.fesg.gate);
	create_wall(app, &game);
}

void	snake_game(t_data *app)
{
	game_window(app);
	//put_map(app);
}


// BUTTONS

int		on_destroy(int keycode, t_data *app)
{
	exit(0);
	return (0);
}

int		on_escape(int keycode, t_data *app)
{
	if (keycode == XK_Escape)
	{
		if (app->win2)
			mlx_destroy_window(app->mlx, app->win2);
		else
			exit(0);
	}	
	return (0);
}

int play_box(int mouse_x, int mouse_y)
{
	int min_x = 354;
	int max_x = 719;
	int min_y = 848;
	int max_y = 983;

	if (mouse_x >= min_x && mouse_x <= max_x && mouse_y >= min_y && mouse_y <= max_y)
		return 1;
	return 0;
}

int on_mouse_click(int button, int mouse_x, int mouse_y, t_data *app)
{

	if (play_box(mouse_x, mouse_y))
		snake_game(app);
	return 0;
}

void	hooks(t_data *app)
{
	mlx_hook(app->win1, 17, 0, on_destroy, app);		// "X" button of the window
	mlx_key_hook(app->win1, on_escape, app); 			// ESC key
	mlx_mouse_hook(app->win1, on_mouse_click, app);
}

// INITIALISING THE APP
void    init(t_data *ptr)
{
	int	xpix;
	int	ypix;

	xpix = 1024;
	ypix = 1024;
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
		return (write(1, "Error\n", 6), 1);
	// define the main window
	ptr->win1 = mlx_new_window(ptr->mlx, xpix, ypix, "Maze Munch");
	if (!ptr->win1)
		destroy_game(ptr);
	
	// define the image of the main window
	ptr->imgw1 = mlx_xpm_file_to_image(ptr->mlx, "assets/xpm/begin.xpm", &xpix, &ypix);
	if (!ptr->imgw1)
		destroy_game(ptr);

	// put the image to the window at the center of it
	mlx_put_image_to_window(ptr->mlx, ptr->win1, ptr->imgw1, 0, 0);
}


int main(void)
{
	t_data  		app;	

	initalize_data(&app);
	app.map = check_map("assets/maps/round1.ber");
	ft_printf("mem addr map -->> %x\n", app.map);

	init(&app);
	hooks(&app);

	mlx_loop(app.mlx);
	destroy_game(&app);
	return (0);
}
*/

/*WALFREE
static void	wall_free(t_map_walls_addr *ptr)
{
	free(ptr->corner);
	free(ptr->hor_left);
	free(ptr->hor_right);
	free(ptr->hor_wall);
	free(ptr->ver_down);
	free(ptr->ver_up);
	free(ptr->ver_wall);
	free(ptr->bg);
}
*/

/*FSEGFREE

static void	fseg_free(t_map_fesg_addr *ptr)
{
	free(ptr->food);
	free(ptr->enemy);
	free(ptr->gate);
	free(ptr->snake_bdead);
	free(ptr->snake_body);
	free(ptr->snake_hdead);
	free(ptr->snake_head);
	
}
*/

#include "mlx/mlx.h"
#include "libft/libft.h"
#include "checker/checker.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <math.h>

/* -------- WINDOW 2 traspassed into files -----------

void	initalize_data(t_data *ptr)
{
	ptr->game = NULL;
	ptr->mlx = NULL;
	ptr->win1 = NULL;
	ptr->win2 = NULL;
	ptr->imgw1 = NULL;
	ptr->map = NULL;
	ptr->xw2 = 0;
	ptr->yw2 = 0;
}

static void	wall_init(t_data *app)
{
	app->game->spr.walls.corner = "assets/xpm/corner.xpm";
	app->game->spr.walls.hor_left = "assets/xpm/hor_left.xpm";
	app->game->spr.walls.hor_wall = "assets/xpm/hor_wall.xpm";
	app->game->spr.walls.hor_right = "assets/xpm/hor_right.xpm";
	app->game->spr.walls.ver_up = "assets/xpm/ver_up.xpm";
	app->game->spr.walls.ver_down = "assets/xpm/ver_down.xpm";
	app->game->spr.walls.ver_wall = "assets/xpm/ver_wall.xpm";
	app->game->spr.walls.bg = "assets/xpm/background.xpm";
}

static void	fseg_init(t_data *app)
{
	app->game->spr.fesg.food = "assets/xpm/egg.xpm";
	app->game->spr.fesg.enemy = "assets/xpm/enemy.xpm";
	app->game->spr.fesg.gate = "assets/xpm/gate.xpm";
	app->game->spr.fesg.snake_bdead = "assets/xpm/snake_bdead.xpm";
	app->game->spr.fesg.snake_body = "assets/xpm/snake_body.xpm";
	app->game->spr.fesg.snake_hdead = "assets/xpm/snake_hdead.xpm";
	app->game->spr.fesg.snake_head = "assets/xpm/snake_head.xpm";
	
}

void    assign_image(t_data *app, void **image, char *addr)
{
	int width;
	int height;

	width = 42;
	height = 42;
	*image = mlx_xpm_file_to_image(app->mlx, addr, &width, &height);
	if (!(*image))
		destroy_game(app);
}

void    deploy_image(t_data *app, void *image, int x, int y)
{
	mlx_put_image_to_window(app->mlx, app->win2, image, x, y);
}

void    put_corners(t_data *app)
{
	t_walls				*img;
	t_map_walls_addr	*addr;
	
	img = &(app->game->wall);
	addr = &(app->game->spr.walls);
	assign_image(app, &(img->corner), addr->corner);
	assign_image(app, &(img->lr_up), addr->ver_up);
	assign_image(app, &(img->lr_down), addr->ver_down);
	assign_image(app, &(img->ud_left), addr->hor_left);
	assign_image(app, &(img->ud_right), addr->hor_right);
	deploy_image(app, img->corner, 0, 0);
	deploy_image(app, img->corner, 0, app->yw2 - IMAGE);
	deploy_image(app, img->corner, app->xw2 - IMAGE, 0);
	deploy_image(app, img->corner, app->xw2 - IMAGE, app->yw2 - IMAGE);
	deploy_image(app, img->lr_up, 0, IMAGE);
	deploy_image(app, img->lr_up, app->xw2 - IMAGE, IMAGE);
	deploy_image(app, img->lr_down, 0, app->yw2 - (IMAGE * 2));
	deploy_image(app, img->lr_down, app->xw2 - IMAGE, app->yw2 - (IMAGE * 2));
	deploy_image(app, img->ud_left, IMAGE, 0);
	deploy_image(app, img->ud_left, IMAGE, app->yw2 - IMAGE);
	deploy_image(app, img->ud_right, app->xw2 - (IMAGE * 2), 0);
	deploy_image(app, img->ud_right, app->xw2 - (IMAGE * 2), app->yw2 - IMAGE);
}

void    put_borders(t_data *app)
{
	t_walls				*img;
	t_map_walls_addr	*addr;
	int x;
	int y;

	img = &(app->game->wall);
	addr = &(app->game->spr.walls);
	x = IMAGE * 2;
	y = IMAGE * 2;
	put_corners(app);
	assign_image(app, &(img->side_hor), addr->hor_wall);
	assign_image(app, &(img->side_ver), addr->ver_wall);
	while (x < (app->xw2 - IMAGE * 2))
	{
		deploy_image(app, img->side_hor, x, app->yw2 - IMAGE);
		deploy_image(app, img->side_hor, x, 0);
		x += IMAGE;
	}
	while (y < (app->yw2 - IMAGE * 2))
	{
		deploy_image(app, img->side_ver, 0, y);
		deploy_image(app, img->side_ver, app->xw2 - IMAGE, y);
		y += IMAGE;
	}
}

void    put_background(t_data *app)
{
	t_walls				*img;
	t_map_walls_addr	*addr;
	int x;
	int	y;

	x = 42;
	img = &(app->game->wall);
	addr = &(app->game->spr.walls);
	assign_image(app, &(img->bg), addr->bg);
	while (x < app->xw2)
	{
		y = 42;
		while (y < app->yw2)
		{
			deploy_image(app, img->bg, x, y);
			y += 42;
		}
		x += 42;
	}
}
*/



void	game_window(t_data *app)
{
	int	i;

	i = 0;
	while(app->map[i] != NULL)
		i++;
	app->xw2 = (ft_strlen(app->map[i - 1])) * BLOCK;
	app->yw2 = (i - 1) * BLOCK;
	app->win2 = mlx_new_window(app->mlx, app->xw2, app->yw2, "The journey");
	if (!app->win2)
		destroy_game(app);
	put_immutable(app);
}

int main(void)
{
	t_data  		app;	
	t_map			map;

	app.game = &map;
	initalize_data(&app);
	checker(&app, "assets/maps/round1.ber");
	init_win1(&app);
	hooks(&app);

	mlx_loop(app.mlx);
	destroy_game(&app);
	return (0);
}





/*CHECKERS

void    free_app(t_data *app)
{
   int i;

	if (app->game)
		free(app->game);
	if (!app->map || !(*app->map))
		return;
	i = 0;
	while(app->map[i] != NULL)
	{
		free(app->map[i]);
		i++;
	}
	free(app->map);
	app->map = NULL; 
}

void return_error(t_data *app)
{
	free_app(app);
	ft_printf("Wrong format of the map!\n");
	exit(EXIT_FAILURE);
}


static int	count_lines(char *argv)
{
	int		fd;
	int		count;
	int		bytes;
	int		i;
	char	buffer[BUFFER_SZ];

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes = read(fd, buffer, BUFFER_SZ);
	if (bytes < 0)
		return (close(fd), 0);
	buffer[bytes] = '\0';
	i = 0;
	count = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	close(fd);
	return (++count);
}

static int	check_wall(t_data *app, int last_row)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	while (app->map[++i] != NULL)
	{
		j = -1;
		len = ft_strlen(app->map[i]);
		if (ft_strchr(app->map[i], '\n'))
			len -= 2; // -1 for \n, -1 for the last 1. This variable is for comprobation of the else if
		if (app->map[i][++j] != '1')
			return_error(app);
		while (app->map[i][++j] != '\n' && app->map[i][j] != '\0')
		{
			
			if ((i == 0 || i == last_row) && app->map[i][j] != '1')
				return_error(app);
			else if ((i > 0 && i < last_row) && j < len && app->map[i][j] == '1')
				return_error(app);
		}
		if (app->map[i][--j] != '1')
			return_error(app);
	}
	return (1);
}

static int	check_format(t_data *app)
{
	int 	i;
	int		len;
	int		test;

	i = -1;
	while (app->map[++i] != NULL)
	{
		if (i == 0)
			len = ft_strlen(app->map[i]);
		else
		{
			test = ft_strlen(app->map[i]);
			if (!ft_strchr(app->map[i], '\n'))
				len -= 1;		// -1 because of the char new line at the end of the string
			if (len != test)
				return_error(app);
		}
	}
	if (test == i)
		return_error(app);
	if (check_wall(app, --i)) // --i for the last row of the map
		return (1);
	return (0);
}

static void	read_map(t_data *app, char *argv)
{
	int		fd;
	int		lines;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error reading the map!\n", 23);
		return_error(app);
	}
	lines = count_lines(argv);
	app->map = malloc((lines + 1) * sizeof(char *));
	if (!app->map)
	{
		close(fd);
		return_error(app);
	}
	i = -1;
	while (++i < lines)
		app->map[i] = get_next_line(fd);
	app->map[i] = NULL;
}

void	check_map(t_data *app, char *argv)
{
	int     i;
	int     j;

	read_map(app, argv);
	if (!app->map)
		return_error(app);
	i = 0;
	while (app->map[i] != NULL)
	{
		j = 0;
		while (app->map[i][j] != '\0' && app->map[i][j] != '\n')
		{
			if (!ft_strchr("01EPC", app->map[i][j]))
				return_error(app);
			j++;                
		}
		i++;
	}
	if (check_format(app))
		return ;
	return_error(app);
}

static void	check_snake(t_data *app)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (app->map[++i] != NULL)
	{
		j = 0;
		while (app->map[i][++j] != NULL)
		{
			if (app->map[i][j] == 'P')
				s++;
		}
	}
	if (s != 1)
		return_error(app);	
}

static void	check_exit(t_data *app)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (app->map[++i] != NULL)
	{
		j = 0;
		while (app->map[i][++j] != NULL)
		{
			if (app->map[i][j] == 'E')
				s++;
		}
	}
	if (s != 1)
		return_error(app);			
}

int checker(t_data *app, char *argv)
{
	check_map(app, argv);
	check_exit(app);
	check_snake(app);
}

*/

/* solong.h
//	WALL, COLLECTIBLES, ENEMY, PLAYER, EXIT ADDRESES
typedef	struct Map_walls
{
	char	*corner;
	char	*hor_left;
	char	*hor_right;
	char	*hor_wall;
	char	*ver_up;
	char	*ver_down;
	char	*ver_wall;
}	t_map_walls_addr;

typedef	struct Map_fesg
{
	char	*food;
	char	*enemy;
	char	*snake_head;
	char	*snake_body;
	char	*snake_hdead;
	char	*snake_bdead;
	char	*gate;
	char    *bg;
}	t_map_fesg_addr;

typedef struct	Sprites_addr
{
	t_map_walls_addr	walls;
	t_map_fesg_addr		fesg;
}	t_sprites;

// (INGAME) SNAKE

typedef struct Snake_body
{
	void	*body;
	int		x_pos;
	int		y_pos;
	struct Snake_body	*next;
}	t_sbody;

typedef struct	Snake 
{
	void	*head;
	t_sbody	*ptr;
	int		xh_pos;
	int		yh_pos;
}   t_snake;

// (INGAME) MAP

typedef struct Map_outline
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
	void	*enemy;
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
	char    **map;
	int		xw2;
	int		yw2;
}   t_data;

*/

