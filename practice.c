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

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_scoreboard;
	int		y_scoreboard;
	int		w_scoreboard;	
	int 	h_scoreboard;
}	t_data;

typedef struct	Scoreboard {
	void	*window;
	void	*mlx;
}	t_score;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	handle_close(int keycode, t_data *data)
{
	exit(0);
	return (0);
}

int scoreboard_close(int keycode, t_score *score_data)
{ 
	if (score_data)
		mlx_destroy_window(score_data->mlx, score_data->window);
	return (0);
}

int handle_scoreboard(int button, int x, int y, t_data *data)
{
	static t_score	score;

	if (button == 1)
	{
		if (x >= data->x_scoreboard && x <= data->x_scoreboard + data->w_scoreboard && \
				y >= data->y_scoreboard && y <= data->y_scoreboard + data->h_scoreboard)
		{
			score.mlx = mlx_init();
			
			score.window = mlx_new_window(score.mlx, 300, 200, "Scoreboard");

			mlx_string_put(score.mlx, score.window,
							50, 50, 0x00FF0000, "Your score will be displayed here!");

			mlx_hook(score.window, 17, 0, scoreboard_close, &score);
			if (score.mlx)
				mlx_loop(score.mlx);
			mlx_destroy_display(score.mlx);
			free(score.mlx);
		}
	}
	return (0);
}

int main(void)
{
	int		x, y;
	int		scoreboard;
	t_data  app;

	app.mlx_ptr = mlx_init();
	if (!app.mlx_ptr)
	{
		printf("Error\n");
		return (1);
	}
	app.win_ptr = mlx_new_window(app.mlx_ptr, 2048, 1080, "Snakeasaurus");
	app.img = mlx_new_image(app.mlx_ptr, 800, 600);
	if (!app.win_ptr)
	{
		printf("Error creating window\n");
		mlx_destroy_display(app.mlx_ptr);
		return (1);
	}
	app.addr = mlx_get_data_addr(app.img, &app.bits_per_pixel, &app.line_length,
								&app.endian);
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
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img, (2048 - 800)/2, (1080 - 600)/2);
	
	mlx_hook(app.win_ptr, 17, 0, handle_close, app.mlx_ptr);
	mlx_hook(app.win_ptr, 2, 1L << 0, handle_close, &app);

	mlx_set_font(app.mlx_ptr, app.win_ptr, "10x20");
	mlx_string_put(app.mlx_ptr, app.win_ptr, ((2048 - 800)/2) + 250, ((1080 - 600)/2) - 50, 0x00FFFFFF, "Welcome to Snakeasaurus game!");

	app.x_scoreboard = ((2048 - 800)/2) - 350;
	app.y_scoreboard = ((1080 - 600)/2) + 50;
	app.w_scoreboard = strlen("Scoreboard") * 10;
	app.h_scoreboard = 20;

	mlx_set_font(app.mlx_ptr, app.win_ptr, "10x20");
	mlx_string_put(app.mlx_ptr, app.win_ptr, app.x_scoreboard, app.y_scoreboard, 0x00FF0000, "Scoreboard");

	mlx_mouse_hook(app.win_ptr, handle_scoreboard, &app);

	mlx_loop(app.mlx_ptr);

	mlx_destroy_image(app.mlx_ptr, app.img);
	mlx_destroy_window(app.mlx_ptr, app.win_ptr);
	mlx_destroy_display(app.mlx_ptr);

	free(app.mlx_ptr);

	return (0);
}



