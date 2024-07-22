/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:52:40 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/22 14:40:40 by motuomin         ###   ########.fr       */
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

typedef struct s_screen
{
	int	half_tiles;
	int	half_tile_w;
	int	half_tile_h;
	int	mar_x;
	int	mar_y;
	int	start_x;
}	t_screen;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*img1;
	mlx_image_t	*img2;
	t_map		*map;
	t_screen	*s;

}				t_mlx;

// -- Macros --

# define RES_X 1000
# define RES_Y 1000

// -- Function prototypes --

//		parsing.c
void	init_map(char *file, t_mlx *mlx, t_map *map);

//		memory_functions.c
void	free_mlx_exit(t_mlx *mlx);
int		free_split(char **arr);
int		allocate_map_grid(t_map *map);

//		gridmap.c
int		gridmap(t_map *map, int (*f)(t_map *, int, int));

#endif
