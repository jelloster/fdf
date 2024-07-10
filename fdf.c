#include "fdf.h"

void	draw_points(mlx_image_t *img, t_map map)
{
	int	sep;
	int	margin_x;
	int	margin_y;
	int	w;
	int	h;

	sep = (RES_X - (2 * MARGIN)) / map.w;
	if (sep > (RES_Y - (2 * MARGIN)) / map.h)
		sep = (RES_Y - (2 * MARGIN)) / map.h;
	margin_x = (RES_X - map.w * sep) / 2;
	margin_y = (RES_Y - map.h * sep) / 2;

	h = 0;
	while (h < map.h)
	{
		w = 0;
		while (w < map.w)
		{
			mlx_put_pixel(img, w * sep + margin_x, h * sep + margin_y, map.grid[h][w].c);
			w++;
		}
		h++;
	}
}

/*
void	draw_points(mlx_image_t *img, t_map map)
{
	int	w;
	int	h;
	int	sep;
	int	mid;

	if (map.h > map.w)
	{
		sep = (RES_Y - (2 * MARGIN)) / map.h;
		mid = (RES_X - map.w * sep) / 2;
	}
	else
	{
		sep = (RES_X - (2 * MARGIN)) / map.w;
		mid = (RES_Y - map.h * sep) / 2;
	}

	h = 0;
	while (h < map.h)
	{
		w = 0;
		while (w < map.w)
		{
			if (map.h > map.w)
				mlx_put_pixel(img, w * sep + MARGIN, h * sep + mid, map.grid[h][w].c);
			else
				mlx_put_pixel(img, w * sep + mid, h * sep + MARGIN, map.grid[h][w].c);
			w++;
		}
		h++;
	}
}
*/
