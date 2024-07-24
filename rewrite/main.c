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

static void	init_mlx(t_mlx *mlx);

int	main(int ac, char *av[])
{
	t_mlx	mlx;

	if (ac != 2)
	{
		ft_putstr_fd("Incorrect number of arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	init_mlx(&mlx);
	init_map(av[1], &mlx, mlx.map);

	for (uint32_t y = 0; y < mlx.img1->height; y++) {
		for (uint32_t x = 0; x < mlx.img1->width; x++) 
		    mlx_put_pixel(mlx.img1, x, y, 0x00008B);
        }

	if (mlx_image_to_window(mlx.mlx, mlx.img1, 0, 0) < 0)
		free_mlx_exit(&mlx);
	fdf(&mlx, mlx.map);
	// mlx_key_hook(mlx, &key_hook, NULL);
	mlx_loop(mlx.mlx);
	//mlx_terminate(mlx.mlx);
	free_mlx_exit(&mlx); // make return EXIT_SUCCESS // double free
}

static void	init_mlx(t_mlx *mlx)
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
	mlx -> map = malloc(sizeof(t_map));
}
