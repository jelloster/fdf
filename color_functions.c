#include "fdf.h"

static void	get_point_color(t_point *point, int max_h);
int	ip(int s, int e, int n, int n_max);

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
	int		R;
	int		G;
	int		B;

	R = ip((C1 >> 16) & 0xFF, (C2 >> 16) & 0xFF, point->h, max_h);
	G = ip((C1 >> 8) & 0xFF, (C2 >> 8) & 0xFF, point->h, max_h);
	B = ip(C1 & 0xFF, C2 & 0xFF, point->h, max_h);
	color = (R << 16) | (G << 8) | B;
	point -> c = color;
}

unsigned int	get_gradient_color(t_point p1, t_point p2, int t_l)
{
	unsigned int	color;
	int		newR;
	int		newG;
	int		newB;
	int		l;

	l = dis(p1, p2);
	newR = ip((p2.c >> 16) & 0xFF, (p1.c >> 16) & 0xFF, l, t_l); // ?
	newG = ip((p2.c >> 8) & 0xFF,(p1.c >> 8) & 0xFF,  l, t_l);
	newB = ip(p2.c & 0xFF, p1.c & 0xFF, l, t_l);
	color = (newR << 16) | (newG << 8) | newB;
	return (color);
}
