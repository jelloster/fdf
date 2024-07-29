/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:54:09 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/25 14:57:50 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_hook(mlx_key_data_t keydata, void* param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS); // free memory
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move(mlx, UP);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move(mlx, DOWN);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move(mlx, LEFT);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move(mlx, RIGHT);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		zoom_in(mlx);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		zoom_out(mlx);
	draw_map(mlx, mlx -> map);
}
