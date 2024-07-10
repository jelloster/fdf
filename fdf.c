#include "fdf.h"

static void	draw_isometric_point(int w, int h, t_point *p, t_screen s);

void draw_points(mlx_image_t *img, t_map *map)
{
	t_screen s;
	int	h;
	int	w;

	s.img = img;
	s.sep = (RES_X - (2 * MARGIN)) / map->w;
	if (s.sep > (RES_Y - (2 * MARGIN)) / map->h)
		s.sep = (RES_Y - (2 * MARGIN)) / map->h;
	s.mar_x = (RES_X - map->w * s.sep) / 2;
	s.mar_y = (RES_Y - map->h * s.sep) / 2;
	h = 0;
	while (h < map->h)
	{
	    w = 0;
	    while (w < map->w)
	    {
		draw_isometric_point(w, h, &map->grid[h][w], s);
		w++;
	    }
	    h++;
	}
}

static void	draw_isometric_point(int w, int h, t_point *p, t_screen s)
{
	int	iso_x;
	int	iso_y;
	int	s_x;
	int	s_y;

	iso_x = s.mar_x + w * s.sep;
	iso_y = s.mar_y + h * s.sep;
	s_x = (iso_x - iso_y) * cos(M_PI / 6);
	s_y = (iso_x + iso_y) * sin(M_PI / 6) - p -> h;
	p -> res_x = s_x;
	p -> res_y = s_y;
	mlx_put_pixel(s.img, s_x, s_y, p -> c);
}

void	draw_lines(mlx_image_t *img, t_map *map)
{
	int	w;
	int	h;

	h = 0;
	while (h < map->h)
	{
		w = 0;
		while (w < map->w)
		{
			if (w != map -> w - 1)
				draw_line(img, map->grid[h][w], map->grid[h][w + 1]);
			if (h != map -> h - 1)
				draw_line(img, map->grid[h][w], map->grid[h + 1][w]);
			w++;
		}
		h++;
	}
}
