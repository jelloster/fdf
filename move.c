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
			// draw_pixel at the same time?
		}
	}
}
