/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/09/12 15:46:35 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_point_color(t_point *point, t_map map)
{
	unsigned int	res;
	t_color			c;
	int				x;

	x = map.max - point -> value;
	c.r = ip((C2 >> 24) & 0xFF, (C1 >> 24) & 0xFF, x, map.range);
	c.g = ip((C2 >> 16) & 0xFF, (C1 >> 16) & 0xFF, x, map.range);
	c.b = ip((C2 >> 8) & 0xFF, (C1 >> 8) & 0xFF, x, map.range);
	c.a = ip(C2 & 0xFF, C1 & 0xFF, x, map.range);
	res = (c.r << 24) | (c.g << 16) | (c.b << 8) | c.a;
	point -> c = res;
}

unsigned int	gradient(t_point p1, t_point p2, int t_l)
{
	unsigned int	res;
	t_color			c;
	int				l;

	l = dis(p1, p2);
	c.r = ip((p2.c >> 24) & 0xFF, (p1.c >> 24) & 0xFF, l, t_l);
	c.g = ip((p2.c >> 16) & 0xFF, (p1.c >> 16) & 0xFF, l, t_l);
	c.b = ip((p2.c >> 8) & 0xFF, (p1.c >> 8) & 0xFF, l, t_l);
	c.a = ip(p2.c & 0xFF, p1.c & 0xFF, l, t_l);
	res = (c.r << 24) | (c.g << 16) | (c.b << 8) | c.a;
	return (res);
}

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
