/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/09/12 18:12:09 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_struct(t_bresenhamn *b, t_point p1, t_point p2);

#include <stdio.h> //delete this

// Bresenhamn's line algorithm
void	draw_line(mlx_image_t *img, t_point p1, t_point p2)
{
	t_bresenhamn	b;

	init_struct(&b, p1, p2);
	while (1)
	{
		if (p1.res_x < RES_X && p1.res_y < RES_Y
			&& p1.res_x > 0 && p1.res_y > 0)
			mlx_put_pixel(img, p1.res_x, p1.res_y, b.color);
		else if ((p1.res_x > RES_X && b.ddx > 0) 
			|| (p1.res_y > RES_Y && b.ddy > 0) // new
			|| (p1.res_x < 0 && b.ddx < 0)
			|| (p1.res_y < 0 && b.ddy < 0))
			return ; // new
		printf("drawing line ... x: %d, y: %d.\n", p1.res_x, p1.res_y);
		printf("dx: %ld, dy: %ld.\n", b.ddx, b.ddy);
		printf("p1x: %d, p1y: %d.\n", p1.res_x, p1.res_y);
		printf("p2x: %d, p2y: %d.\n", p2.res_x, p2.res_y);
		if (p1.res_x == p2.res_x && p1.res_y == p2.res_y)
			break ;
		b.e2 = b.err * 2;
		if (b.e2 > -b.dy)
		{
			b.err -= b.dy;
			p1.res_x += b.sx;
		}
		if (b.e2 < b.dx)
		{
			b.err += b.dx;
			p1.res_y += b.sy;
		}
		b.color = gradient(p1, p2, b.t_l);
	}
}

static void	init_struct(t_bresenhamn *b, t_point p1, t_point p2)
{
	b->dx = labs((long)p2.res_x - (long)p1.res_x);
	b->ddx = (long)p2.res_x - (long)p1.res_x;
	b->dy = labs((long)p2.res_y - (long)p1.res_y);
	b->ddy = (long)p2.res_y - (long)p1.res_y;
	if (p1.res_x < p2.res_x)
		b->sx = 1;
	else
		b->sx = -1;
	if (p1.res_y < p2.res_y)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx - b->dy;
	b->t_l = dis(p1, p2);
	b->color = gradient(p1, p2, b->t_l);
}
