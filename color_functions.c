/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/25 15:00:11 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_point_color(t_point *point, t_map map);

void	get_point_colors(t_map *map)
{
	int	w;
	int	h;

	h = 0;
	while (h < map -> h)
	{
		w = 0;
		while (w < map -> w)
			get_point_color(&map -> grid[h][w++], *map);
		h++;
	}
}

static void	get_point_color(t_point *point, t_map map)
{
	unsigned int	color;
	int				r;
	int				g;
	int				b;
	int				x;

	x = map.max - point -> value;
	r = ip((C2 >> 16) & 0xFF, (C1 >> 16) & 0xFF, x, map.range);
	g = ip((C2 >> 8) & 0xFF, (C1 >> 8) & 0xFF, x, map.range);
	b = ip(C2 & 0xFF, C1 & 0xFF, x, map.range);
	color = (r << 16) | (g << 8) | b;
	point -> c = color;
}

unsigned int	gradient(t_point p1, t_point p2, int t_l)
{
	unsigned int	color;
	int				r;
	int				g;
	int				b;
	int				l;

	l = dis(p1, p2);
	r = ip((p2.c >> 16) & 0xFF, (p1.c >> 16) & 0xFF, l, t_l);
	g = ip((p2.c >> 8) & 0xFF, (p1.c >> 8) & 0xFF, l, t_l);
	b = ip(p2.c & 0xFF, p1.c & 0xFF, l, t_l);
	color = (r << 16) | (g << 8) | b;
	return (color);
}
