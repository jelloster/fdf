#include "fdf.h"

static void	get_point_color(t_point *point, int max_h);
int ip(int start, int end, t_point *p, int max_h);

void	get_point_colors(t_map *map)
{
	int	w;
	int	h;

	h = 0;
	while (h < map -> h)
	{
		w = 0;
		while (w < map -> w)
			get_point_color(&map -> grid[h][w++], map -> max_h);
		h++;
	}
}

static void	get_point_color(t_point *point, int max_h)
{
	unsigned int	color;
	int		newR;
	int		newG;
	int		newB;

	newR = ip((C1 >> 16) & 0xFF, (C2 >> 16) & 0xFF, point, max_h);
	newG = ip((C1 >> 8) & 0xFF, (C2 >> 8) & 0xFF, point, max_h);
	newB = ip(C1 & 0xFF, C2 & 0xFF, point, max_h);
	color = (newR << 16) | (newG << 8) | newB;
	point -> c = color;
}

int ip(int start, int end, t_point *p, int max_h)
{
	return (start + ((end - start) * p -> h) / max_h);
}
