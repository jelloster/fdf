#include "fdf.h"

void	zoom_in(t_mlx *mlx)
{
	int	h;
	int	w;
	t_map	*map;

	map = mlx -> map;
	h = -1;
	while (++h < mlx -> map -> h)
	{
		w = -1;
		while (++w < mlx -> map -> w)
		{
			map->grid[h][w].res_x += (w - h) * (mlx->s.half_tile_w);
			map->grid[h][w].res_y += (w + h) * (mlx->s.half_tile_h)
			- map->grid[h][w].value * mlx -> s.half_tile_h / 2;
		}
	}
	mlx -> s.half_tile_w *= 2;
	mlx -> s.half_tile_h *= 2;

	draw_map(mlx, mlx -> map);
}

void	zoom_out(t_mlx *mlx)
{
	int	h;
	int	w;
	t_map	*map;
	
	if (mlx -> s.half_tile_w / 2 <= 1)
		return;
	h = -1;
	map = mlx -> map;
	mlx -> s.half_tile_w /= 2;
	mlx -> s.half_tile_h /= 2;
	while (++h < mlx -> map -> h)
	{
		w = -1;
		while (++w < mlx -> map -> w)
		{
			map->grid[h][w].res_x -= (w - h) * (mlx->s.half_tile_w);
			map->grid[h][w].res_y -= (w + h) * (mlx->s.half_tile_h)
			- map->grid[h][w].value * mlx -> s.half_tile_h / 2;
		}
	}
	draw_map(mlx, mlx -> map);
}
