/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/08/12 12:54:52 by motuomin         ###   ########.fr       */
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
	mlx.map = malloc(sizeof(t_map));
	if (!mlx.map)
		exit(EXIT_FAILURE);
	if (!init_map(av[1], mlx.map))
	{
		ft_putstr_fd("Map error.\n", 2);
		free(mlx.map);
		exit(EXIT_FAILURE);
	}
	init_mlx(&mlx);
	if (mlx_image_to_window(mlx.mlx, mlx.img1, 0, 0) < 0)
		free_mlx_exit(&mlx, EXIT_FAILURE);
	fdf(&mlx, mlx.map);
	mlx_key_hook(mlx.mlx, &key_hook, &mlx);
	mlx_loop(mlx.mlx);
	free_mlx_exit(&mlx, EXIT_SUCCESS);
}

static void	init_mlx(t_mlx *mlx)
{
	mlx -> mlx = mlx_init(RES_X, RES_Y, "fdf", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx -> img1 = mlx_new_image(mlx -> mlx, RES_X, RES_Y);
	if (!mlx -> img1)
		free_mlx_exit(mlx, EXIT_FAILURE);
}
