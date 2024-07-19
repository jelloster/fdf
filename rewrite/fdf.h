/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:52:40 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/19 18:32:22 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// -- Includes --

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "../MLX42/include/MLX42/MLX42.h" // fix
# include "../libft/inc/libft.h" // fix

// -- Typedefs --

typedef struct s_point
{
	int	res_x;
	int	res_y;
	int	value;
}		t_point;

typedef struct s_map
{
	int		h;
	int		w;
	int		max;
	int		min;
	int		range;
	t_point	**grid;
}			t_map;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*img1;
	mlx_image_t	*img2;
	t_map		*map;

}				t_mlx;

// -- Macros --

# define RES_X 1000
# define RES_Y 1000

// -- Function prototypes --

//		parsing.c
void	init_map(char *file, t_mlx *mlx, t_map *map);

//		memory_functions.c
void	free_mlx_exit(t_mlx *mlx);

#endif
