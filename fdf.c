#include "fdf.h"

static void	draw_isometric_point(int x, int y, t_point *p, t_screen s);

#include <stdio.h> // remove

void draw_points(mlx_image_t *img, t_map *map)
{
	t_screen s;
	int	h;
	int	w;

	s.img = img;
	s.map = map;

	// Get image width
	int	image_width = RES_X - 2 * MARGIN;
	printf("RES_X = %d, MARGIN = %d, image_width : %d\n", RES_X, MARGIN, image_width);

	// Half tile width
	printf("map height : %d, map width : %d\n", map->h, map->w);
	if (map->w < map->h)
		s.v_half_tiles = (map->w * 2 + (map->h - map->w));
	else
		s.v_half_tiles = (map->h * 2 + (map->w - map->h));

	printf("Vertical half tiles: %d\n", s.v_half_tiles);
	s.half_tile_w = RES_X / s.v_half_tiles;
	s.t_w = 2 * s.half_tile_w;
	s.t_h = s.t_w * tan(M_PI / 6);
	printf("tile width : %d, tile heigth : %d\n", s.t_w, s.t_h);

	// Get margins based on tile width and heigth
	// s.mar_x = (RES_X - s.half_tile_w * s.v_half_tiles) / 2;
	s.mar_x = MARGIN;
	s.mar_y = (RES_Y - map->h * s.t_h) / 2;
	printf("res x : %d, res y : %d\n", RES_X, RES_Y);
	printf("mar x : %d, mar y : %d\n", s.mar_x, s.mar_y);

	// Find starting point (x of left upper corner) to center isometric image
	map->start = map->h * s.half_tile_w;
	printf("start x : %d\n", map->start);

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

	s_x = s.map->start + (x - y) * (s.half_tile_w);
	s_y = s.mar_y + ((x + y) * (s.t_h / 2)) - p -> h * s.t_h / 4;
	if (x == 0 && y == 0)
		printf("s_x = %d\n", s_x);
	p -> res_x = s_x;
	p -> res_y = s_y;
	printf("x: %d, y: %d.\n", s_x, s_y);
	if (s_x <= RES_X && s_y <= RES_Y)
		mlx_put_pixel(s.img, s_x, s_y, p -> c); // seg fault
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
