#include "fdf.h"

static void    draw_map(t_mlx *mlx);

void    fdf(t_mlx *mlx, t_map *map)
{
    get_screen_info(map, mlx->s);
    get_screen_coords(map, mlx->s);
    draw_map(mlx);
}

static void    draw_map(t_mlx *mlx)
{
	int	h;
	int	w;
    mlx_image_t img;

    img = mlx -> img1;
	h = 0;
    while (h < map->h)
	{
		w = 0;
		while (w < map -> w)
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