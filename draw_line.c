#include "fdf.h"

// Bresenhamn's line algorithm
void draw_line(mlx_image_t *img, t_point p1, t_point p2)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;
    int t_l;

    dx = abs(p2.res_x - p1.res_x); 
    dy = abs(p2.res_y - p1.res_y);
    sx = p1.res_x < p2.res_x ? 1 : -1;
    sy = p1.res_y < p2.res_y ? 1 : -1;
    err = dx - dy;
    t_l = dis(p1, p2);

    while (1)
    {
		ft_printf("x : %d, y: %d\n", p1.res_x, p1.res_y);
		if (p1.res_x <= RES_X && p1.res_y <= RES_Y
			&& p1.res_x > 0 && p1.res_y > 0)
			mlx_put_pixel(img, p1.res_x, p1.res_y, get_gradient_color(p1, p2, t_l)); // seg fault
        if (p1.res_x == p2.res_x && p1.res_y == p2.res_y)
            break;
        e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            p1.res_x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            p1.res_y += sy;
        }
    }
}
