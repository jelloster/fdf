#include "fdf.h"

void	draw_points(mlx_image_t *img, t_map *map)
{
	int	sep;
	int	margin_x;
	int	margin_y;
	int	w;
	int	h;

	sep = (RES_X - (2 * MARGIN)) / map->w;
	if (sep > (RES_Y - (2 * MARGIN)) / map->h)
		sep = (RES_Y - (2 * MARGIN)) / map->h;
	margin_x = (RES_X - map->w * sep) / 2;
	margin_y = (RES_Y - map->h * sep) / 2;

	h = 0;
	while (h < map->h)
	{
		w = 0;
		while (w < map->w)
		{
			map->grid[h][w].res_x = w * sep + margin_x;
			map->grid[h][w].res_y = h * sep + margin_y - map->grid[h][w].h;
			mlx_put_pixel(img, map->grid[h][w].res_x, map->grid[h][w].res_y - map->grid[h][w].h, map->grid[h][w].c);
			w++;
		}
		h++;
	}
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
