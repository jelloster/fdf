/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/22 14:40:40 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_mlx(t_mlx *mlx, char *file);
void		free_mlx_exit(t_mlx *mlx);

int	main(int ac, char *av[])
{
	t_mlx	mlx;

	if (ac != 2)
	{
		ft_putstr_fd("Incorrect number of arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	init_mlx(&mlx, av[1]);
	init_map(av[1], &mlx, mlx.map);
	if (mlx_image_to_window(mlx.mlx, mlx.img1, 0, 0) < 0)
		free_mlx_exit(&mlx);

	fdf(mlx);

	// mlx_key_hook(mlx, &key_hook, NULL);
	mlx_loop(mlx.mlx);
	mlx_terminate(mlx.mlx);
	free_mlx_exit(&mlx); // make return EXIT_SUCCESS
}

static void	init_mlx(t_mlx *mlx, char *file)
{
	mlx -> mlx = mlx_init(RES_X, RES_Y, "fdf", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx -> img1 = mlx_new_image(mlx -> mlx, RES_X, RES_Y);
	if (!mlx -> img1)
		free_mlx_exit(mlx);
	mlx -> img2 = mlx_new_image(mlx -> mlx, RES_X, RES_Y);
	if (!mlx -> img2)
		free_mlx_exit(mlx);
}

void	get_screen_info(t_map *map, t_screen *s)
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
	s -> half_tile_h = s -> half_tile_w * tan(M_PI / 6);
	s -> start_x = map -> h * s -> half_tile_w + left_over_width;
	// kusee kai joskus
	s->mar_x = (RES_X - s -> half_tiles * s -> half_tile_w) / 2;
	s->mar_y = (RES_Y - s -> half_tiles * s -> half_tile_h) / 2;
}

void	get_screen_coords(t_map *map, t_screen *s)
{
	int	h;
	int	w;
	t_point	*p;

	h = 0;
	while (h < map->h)
	{
	    w = -1;
	    while (++w < map->w)
		{
			p = & map -> grid[h][w];
			p->res_x = s->start_x + (w - h) * (s->half_tile_w);
			p->res_y = s->mar_y + ((w + h) * (s->half_tile_h)) - p->value  * 2;
			if (p->res_y > s->max_res_y)
				s->max_res_y = p->res_y;
			if (p->res_y < s->min_res_y)
				s->min_res_y = p->res_y;
		}
	    h++;
	}
	// fix
	if (s->max_res_y > RES_Y || s->min_res_y < 0)
	{
		ft_printf("The map is too big");
		exit(1);
	}
}
