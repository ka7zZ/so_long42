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




void	*img_border;
void	*s_win;
int		sx_pos = 50;
int		sy_pos = 10;






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

int		on_destroy(int keycode, t_data *data)
{
	
	exit(0);
	return (0);
}

int		on_escape(int keycode, t_data *data)
{
	printf("keycode: %d\n", keycode);
	if (keycode == XK_Escape)
		exit(0);
	return (0);
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
				return (1);
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


int main(void)
{
	int		background_posx;
	int		background_posy;
	int		head_posx;
	int		head_posy;
	int		x;
	int		y;
	char	*win_str;
	t_data  app;
	t_score	s_board;
	t_snake	head;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("Error\n");
		return (1);
	}
	// define the main window
	app.win_ptr = mlx_new_window(mlx, 2000, 1000, "Snakeasaurus");
	if (!app.win_ptr)
	{
		mlx_destroy_display(mlx);
		return (1);
	}
	// define the image of the main window
	app.img = mlx_new_image(mlx, 800, 600); // 800 x 600 = size of the image
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

	// put the image to the window at the center of it
	mlx_put_image_to_window(mlx, app.win_ptr, app.img, background_posx, background_posy);
	
	// Define exit buttons
	mlx_hook(app.win_ptr, 17, 0, on_destroy, &app);		// "X" button of the window
	mlx_key_hook(app.win_ptr, on_escape, mlx); 			// ESC key

	// set FONT of all the writtings of the window
	mlx_set_font(mlx, app.win_ptr, "10x20");
	// put a text into window at the precise position
	win_str = "Welcome to Snakeasaurus game!";
	mlx_string_put(mlx, app.win_ptr, ((2048 - 800)/2) + 250, ((1080 - 600)/2) - 50, 0x00FFFFFF, win_str);
	
	// setting second_window_position's values
	second_window_position(&s_board);

	mlx_string_put(mlx, app.win_ptr, s_board.x_pos, s_board.y_pos, 0x00FF0000, s_board.name);

	mlx_mouse_hook(app.win_ptr, handle_scoreboard, &s_board);

	mlx_loop(mlx);

	mlx_destroy_image(mlx, app.img);
	mlx_destroy_window(mlx, app.win_ptr);
	mlx_destroy_display(mlx);

	return (0);
}
