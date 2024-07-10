#include "fdf.h"

// Bresenhamn's line algorithm
void	draw_line(mlx_image_t *img, t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;

	dx = ABS(p2.x - p1.x);
	dy = ABS(p2.y - p1.y);
	err = dx - dy;
	if (p1.x < p2.x)
		sx = 1;
	else
		sx = -1;
	if (p1.y < p2.y)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		mlx_put_pixel(img, p1.x, p1.y, C1);
		if (p1.x != p2.x && p1.y != p2.y)
			break;
		// Move horizontally
		if (err * 2 > -dy)
		{
			err -= dy;
			p1.x += sx;
		}
		// Move vertically
		if (err * 2 > -dx)
		{
			err += dx;
			p1.y += sy;
		}
	}
}
