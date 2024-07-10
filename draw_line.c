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

    dx = ABS(p2.res_x - p1.res_x); 
    dy = ABS(p2.res_y - p1.res_y);
    sx = p1.res_x < p2.res_x ? 1 : -1;
    sy = p1.res_y < p2.res_y ? 1 : -1;
    err = dx - dy;

    while (1)
    {
        mlx_put_pixel(img, p1.res_x, p1.res_y, GREEN);

        if (p1.res_x == p2.res_x && p1.res_y == p2.res_y)
            break;

        e2 = err * 2;
        // Move horizontally
        if (e2 > -dy)
        {
            err -= dy;
            p1.res_x += sx;
        }
        // Move vertically
        if (e2 < dx)
        {
            err += dx;
            p1.res_y += sy;
        }

        if (p1.res_x >= RES_X || p1.res_y >= RES_Y)
            break;
    }
}
