/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/08/12 12:25:17 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_mlx *mlx)
{
	int		h;
	int		w;
	t_map	*map;

	map = mlx -> map;
	h = -1;
	while (++h < mlx -> map -> h)
	{
		w = -1;
		while (++w < mlx -> map -> w)
		{
			map->grid[h][w].x += (w - h) * (mlx->s.half_tile_w);
			map->grid[h][w].y += (w + h) * (mlx->s.half_tile_h) \
			- map->grid[h][w].value * mlx -> s.half_tile_h / 2;
		}
	}
	mlx -> s.half_tile_w *= 2;
	mlx -> s.half_tile_h *= 2;
	draw_map(mlx, mlx -> map);
}

void	zoom_out(t_mlx *mlx)
{
	int		h;
	int		w;
	t_map	*map;

	if (mlx -> s.half_tile_w / 2 <= 3)
		return ;
	h = -1;
	map = mlx -> map;
	mlx -> s.half_tile_w /= 2;
	mlx -> s.half_tile_h /= 2;
	while (++h < mlx -> map -> h)
	{
		w = -1;
		while (++w < mlx -> map -> w)
		{
			map->grid[h][w].x -= (w - h) * (mlx->s.half_tile_w);
			map->grid[h][w].y -= (w + h) * (mlx->s.half_tile_h) \
			- map->grid[h][w].value * mlx -> s.half_tile_h / 2;
		}
	}
	draw_map(mlx, mlx -> map);
}
