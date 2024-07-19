#include "fdf.h"

void	init_map(char *file, t_mlx *mlx, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_mlx_exit();
		
}
