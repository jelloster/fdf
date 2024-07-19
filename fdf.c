#include "fdf.h"

static void	draw_isometric_point(int x, int y, t_point *p, t_screen s);
void	init_screen(t_map *map, t_screen *s, mlx_image_t *img);

#include <stdio.h> // remove

void draw_points(mlx_image_t *img, t_map *map)
{
	t_screen s;
	int	h;
	int	w;

	init_screen(map, &s, img);
	printf("res x : %d, res y : %d\n", RES_X, RES_Y);
	printf("mar x : %d, mar y : %d\n", s.mar_x, s.mar_y);

	h = 0;
	while (h < map->h)
	{
	    w = -1;
	    while (++w < map->w)
			draw_isometric_point(w, h, &map->grid[h][w], s);
	    h++;
	}
}

void	init_screen(t_map *map, t_screen *s, mlx_image_t *img)
{
	int	left_over;

	left_over = 0;
	s -> img = img;
	s -> map = map;

	if (map->w < map->h)
		s -> half_tiles = (map->w * 2 + (map->h - map->w));
	else
		s -> half_tiles = (map->h * 2 + (map->w - map->h));
	if (RES_X > RES_Y)
	{
		s -> half_tile_w = RES_Y / s -> half_tiles;
		left_over = (RES_X - RES_Y) / 2;
	}
	else
		s -> half_tile_w = RES_X / s -> half_tiles;
	s -> half_tile_h = s -> half_tile_w * tan(M_PI / 6);
	printf("half_tile_h : %d\n", s->half_tile_h);
	s->mar_x = (RES_X - s -> half_tiles * s -> half_tile_w) / 2;
	s->mar_y = (RES_Y - s->half_tiles * s->half_tile_h) / 2;

	map->start = map->h * s -> half_tile_w + left_over;
}

static void	draw_isometric_point(int x, int y, t_point *p, t_screen s)
{
	int	s_x;
	int	s_y;

	s_x = s.map->start + (x - y) * (s.half_tile_w);
	s_y = s.mar_y + ((x + y) * (s.half_tile_h)) - p->h * 2; // get good height multiplier
	p -> res_x = s_x;
	p -> res_y = s_y;
	if (s_x > 0 && s_x <= RES_X && s_y > 0 && s_y <= RES_Y)
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
