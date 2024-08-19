/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/25 15:00:11 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_screen_info(t_map *map, t_screen *s);
static void	get_screen_coords(t_map *map, t_screen *s);

void	fdf(t_mlx *mlx, t_map *map)
{
	get_screen_info(map, &mlx->s);
	get_screen_coords(map, &mlx->s);
	draw_map(mlx, map);
}

static void	get_screen_info(t_map *map, t_screen *s)
{
	int	left_over_width;

	left_over_width = 0;
	if (map -> w < map -> h)
		s -> half_tiles = (map -> w * 2 + (map -> h - map -> w));
	else
		s -> half_tiles = (map -> h * 2 + (map -> w - map -> h));
	if (RES_X > RES_Y)
	{
		s -> half_tile_w = RES_Y / s -> half_tiles;
		left_over_width = (RES_X - RES_Y) / 2;
	}
	else
		s -> half_tile_w = RES_X / s -> half_tiles;
	if (s -> half_tile_w < 2)
		s -> half_tile_w = 2;
	s -> half_tile_h = s -> half_tile_w * tan(M_PI / 6);
	s -> start_x = map -> h * s -> half_tile_w + left_over_width;
	s->mar_x = (RES_X - s -> half_tiles * s -> half_tile_w) / 2;
	s->mar_y = (RES_Y - s -> half_tiles * s -> half_tile_h) / 2;
}

static void	get_screen_coords(t_map *map, t_screen *s)
{
	int		h;
	int		w;
	int		h_multip;
	t_point	*p;

	h = 0;
	h_multip = s->half_tile_h / 2;
	//h_multip = RES_Y / map -> range;
	if (h_multip < 1)
		h_multip = 1;
	while (h < map->h)
	{
		w = -1;
		while (++w < map->w)
		{
			p = & map -> grid[h][w];
			p->res_x = s->start_x + (w - h) * (s->half_tile_w);
			p->res_y = s->mar_y + ((w + h) \
				* (s->half_tile_h)) - p->value * h_multip;
			if (p->res_y > s->max_res_y)
				s->max_res_y = p->res_y;
			if (p->res_y < s->min_res_y)
				s->min_res_y = p->res_y;
		}
		h++;
	}
}

void	draw_map(t_mlx *mlx, t_map *map)
{
	int			h;
	int			w;
	mlx_image_t	*img;

	img = mlx -> img1;
	h = 0;
	background_color(mlx, BG_C);
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
