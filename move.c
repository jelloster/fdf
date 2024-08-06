/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/25 15:00:11 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_mlx *mlx, t_dir dir)
{
	int	h;
	int	w;
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	if (dir == UP)
		dy = 1;
	if (dir == DOWN)
		dy = -1;
	if (dir == LEFT)
		dx = 1;
	if (dir == RIGHT)
		dx = -1;
	h = -1;
	while (++h < mlx -> map -> h)
	{
		w = -1;
		while (++w < mlx -> map -> w)
		{
			mlx -> map -> grid[h][w].res_x += dx * MOVE_AMOUNT;
			mlx -> map -> grid[h][w].res_y += dy * MOVE_AMOUNT;
		}
	}
}
