#include "so_long.h"

static int play_button(int mouse_x, int mouse_y)
{
    int min_x = 354;
    int max_x = 719;
    int min_y = 848;
    int max_y = 983;

    if (mouse_x >= min_x && mouse_x <= max_x && mouse_y >= min_y && mouse_y <= max_y)
        return 1;
    return 0;
}

int on_play(int button, int mouse_x, int mouse_y, t_data *app)
{
    int circle_center_x = 512;
    int circle_center_y = 512;
    int circle_radius = 200;

    if (play_button(mouse_x, mouse_y))
		game_window(app);
    return 0;
}