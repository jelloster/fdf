#include "fdf.h"

static void	draw_isometric_point(int x, int y, t_point *p, t_screen s);

#include <stdio.h> // remove

void draw_points(mlx_image_t *img, t_map *map)
{
	t_screen s;
	int	h;
	int	w;

	s.img = img;

	// Get tile width based on screen width
	s.t_w = (RES_X - 2 * MARGIN) / map -> w;
	// Get tile heigth based on tile width
	s.t_h = s.t_w * tan(M_PI / 6);

	// Get margins based on tile width and heigth
	s.mar_x = (RES_X - map->w * s.t_w) / 2; // not needed rn?
	s.mar_y = (RES_Y - map->h * s. t_h) / 2;

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

static void	draw_isometric_point(int x, int y, t_point *p, t_screen s)
{
	int	s_x;
	int	s_y;

	s_x = RES_X / 2 + ((x - y) * (s.t_w / 2));
	s_y = s.mar_y + ((x + y) * (s.t_h / 2)) - p -> h * 5;
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
