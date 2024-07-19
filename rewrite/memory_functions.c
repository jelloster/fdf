/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:29:54 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/19 18:29:55 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mlx_exit(t_mlx *mlx)
{
	if (mlx -> mlx)
	{
		free (mlx -> mlx);
		mlx -> mlx = NULL;
	}
	if (mlx -> img1)
	{
		free (mlx -> img1);
		mlx -> img1 = NULL;
	}
	if (mlx -> img2)
	{
		free (mlx -> img2);
		mlx -> img2 = NULL;
	}
	// free map grid & map
	exit (EXIT_FAILURE);
}
