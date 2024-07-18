#include "fdf.h"

void	key_hook(mlx_key_data_t keydata, void* param)
{
	void	*ptr;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	ptr = param;
}
