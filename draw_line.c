/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/09/16 15:20:40 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_struct(t_br *b, t_point p1, t_point p2);
static int	calculate_intersection(t_point *p1, t_point *p2);
static void	bresenhamns_loop(mlx_image_t *img, t_point p1, t_point p2, t_br b);

void	draw_line(mlx_image_t *img, t_point p1, t_point p2)
{
	t_br	b;

	if (!calculate_intersection(&p1, &p2))
		return ;
	init_struct(&b, p1, p2);
	bresenhamns_loop(img, p1, p2, b);
}

static void	bresenhamns_loop(mlx_image_t *img, t_point p1, t_point p2, t_br b)
{
	while (1)
	{
		if (p1.x < RES_X && p1.y < RES_Y && p1.x > 0 && p1.y > 0)
			mlx_put_pixel(img, p1.x, p1.y, b.color);
		else if ((p1.x > RES_X && b.ddx > 0) || (p1.y > RES_Y && b.ddy > 0)
			|| (p1.x < 0 && b.ddx < 0) || (p1.y < 0 && b.ddy < 0))
			return ;
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		b.e2 = b.err * 2;
		if (b.e2 > -b.dy)
		{
			b.err -= b.dy;
			p1.x += b.sx;
		}
		if (b.e2 < b.dx)
		{
			b.err += b.dx;
			p1.y += b.sy;
		}
		b.color = gradient(p1, p2, b.t_l);
	}
}

static int	calculate_intersection(t_point *p1, t_point *p2)
{
	if (p1->x < 0)
	{
		if (p2->x != p1->x)
			p1->y += ((p2->y - p1->y) * (-p1->x)) / (p2->x - p1->x);
		p1->x = 0;
	}
	else if (p1->x > RES_X)
	{
		if (p2->x != p1->x)
			p1->y += ((p2->y - p1->y) * (RES_X - p1->x)) / (p2->x - p1->x);
		p1->x = RES_X;
	}
	if (p1->y < 0)
	{
		if (p2->y != p1->y)
			p1->x += (p2->x - p1->x) * (-p1->y) / (p2->y - p1->y);
		p1->y = 0;
	}
	else if (p1->y > RES_Y)
	{
		if (p2->y != p1->y)
			p1->x += (p2->x - p1->x) * (RES_Y - p1->y) / (p2->y - p1->y);
		p1->y = RES_Y;
	}
	return (p1->x >= 0 && p1->x <= RES_X && p1->y >= 0 && p1->y <= RES_Y);
}

static void	init_struct(t_br *b, t_point p1, t_point p2)
{
	b->dx = labs((long)p2.x - (long)p1.x);
	b->ddx = (long)p2.x - (long)p1.x;
	b->dy = labs((long)p2.y - (long)p1.y);
	b->ddy = (long)p2.y - (long)p1.y;
	if (p1.x < p2.x)
		b->sx = 1;
	else
		b->sx = -1;
	if (p1.y < p2.y)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx - b->dy;
	b->t_l = dis(p1, p2);
	b->color = gradient(p1, p2, b->t_l);
}
