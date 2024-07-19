/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/19 18:32:24 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_mlx(t_mlx *mlx, char *file);
void		free_mlx_exit(t_mlx *mlx);

int	main(int ac, char *av[])
{
	t_mlx mlx;

	if (ac != 2)
	{
		ft_putstr_fd("Incorrect number of arguments.\n", 2);
		exit(EXIT_FAILURE);
	}
	init_mlx(&mlx, av[1]);
	init_map(mlx.map);

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

