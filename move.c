#include "fdf.h"

static void	move_pixels(t_map *map, int	dx, int dy);

void	move(t_map *map, t_dir dir)
{

	if (dir == LEFT)
		move_pixels(map, -1, 0);
	if (dir == RIGHT)
		move_pixels(map, 1, 0);
	if (dir == UP)
		move_pixels(map, 0, -1);
	if (dir == DOWN)
		move_pixels(map, 0, 1);
	
	// draw image
}

static void	move_pixels(t_map *map, int	dx, int dy)
{
	int	h;
	int	w;

	h = 0;
	while (h < map->h)
	{
	    w = -1;
	    while (++w < map->w)
		{
			map -> grid[h][w].res_x += dx;
			map -> grid[h][w].res_y += dy;
		}
	    h++;
	}
}
