/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/25 15:00:11 by motuomin         ###   ########.fr       */
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
	if (mlx_image_to_window(mlx.mlx, mlx.img1, 0, 0) < 0)
		free_mlx_exit(&mlx);
	fdf(&mlx, mlx.map);
	mlx_key_hook(mlx.mlx, &key_hook, &mlx);
	mlx_loop(mlx.mlx);
	mlx_terminate(mlx.mlx);
	//free_mlx_exit(&mlx); // make return EXIT_SUCCESS // double free
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
