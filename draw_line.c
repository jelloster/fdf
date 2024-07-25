#include "fdf.h"

static void init_struct(t_bresenhamn *b, t_point p1, t_point p2);

// Bresenhamn's line algorithm
void draw_line(mlx_image_t *img, t_point p1, t_point p2)
{
	t_bresenhamn b;

	init_struct(&b, p1, p2);
	while (1)
	{
		if (p1.res_x <= RES_X && p1.res_y <= RES_Y
			&& p1.res_x > 0 && p1.res_y > 0)
			mlx_put_pixel(img, p1.res_x, p1.res_y, get_gradient_color(p1, p2, b.t_l));
		if (p1.res_x == p2.res_x && p1.res_y == p2.res_y)
			break;
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
	}
}

static void init_struct(t_bresenhamn *b, t_point p1, t_point p2)
{
	b->dx = abs(p2.res_x - p1.res_x); 
	b->dy = abs(p2.res_y - p1.res_y);
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
}
