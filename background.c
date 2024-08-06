/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/25 15:00:11 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background_color(t_mlx *mlx, unsigned int color)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	x = 0;
	while (y < mlx -> img1 -> height)
	{
		x = 0;
		while (x < mlx -> img1 -> width)
		{
			mlx_put_pixel(mlx -> img1, x, y, color);
			x++;
		}
		y++;
	}
}
