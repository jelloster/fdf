/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:25:57 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/09 12:52:56 by jelloster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// --- INCLUDES ---
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/inc/libft.h"

typedef unsigned int t_ui;

typedef struct s_point
{
	int		h;
	int		x;
	int		y;
	int		res_x;
	int		res_y;
	t_ui		c;
}			t_point;

typedef struct	s_map
{
	int	w;
	int	h;
	int	max_h;
	t_point	**grid;
}				t_map;

typedef struct s_coor
{
	int	x;
	int	y;
}			t_coor;

// --- MACROS ---
# define RES_X 400
# define RES_Y 400
# define MARGIN 30

#define ABS(x) ((x) < 0 ? -(x) : (x));

// Colors
# define WHITE        0xFFFFFFFF  // Fully opaque white
# define BLACK        0xFF000000  // Fully opaque black
# define RED          0xFFFF0000  // Fully opaque red
//# define GREEN        0xFF00FF00  // Fully opaque green
# define GREEN        0x0000FF00  // Fully opaque green
# define BLUE         0xFF0000FF  // Fully opaque blue
# define YELLOW       0xFFFFFF00  // Fully opaque yellow
# define CYAN         0xFF00FFFF  // Fully opaque cyan
# define MAGENTA      0xFFFF00FF  // Fully opaque magenta
# define ORANGE       0xFFFFA500  // Fully opaque orange
# define PURPLE       0xFF800080  // Fully opaque purple
# define GRAY         0xFF808080  // Fully opaque gray
# define LIGHT_GRAY   0xFFD3D3D3  // Fully opaque light gray
# define DARK_GRAY    0xFFA9A9A9  // Fully opaque dark gray
# define PINK         0xFFFFC0CB  // Fully opaque pink
# define BROWN        0xFFA52A2A  // Fully opaque brown
# define WHITE 0xFFFFFFFF

# define C1 WHITE
# define C2 RED

# define EXIT_FAILURE 1
# define EXIT_SUCESS 0

// --- FUNCTION PROTOTYPES ---

void	ft_error(void);

// memory_functions.c
int	allocate_map_grid(t_map *map);
int	free_map_grid(t_map *map, int ret);
int	free_split(char **arr);

// parsing.c
void	init_map(char *file, t_map *map);

void	get_point_colors(t_map *map);

void	draw_points(mlx_image_t *img, t_map *map);

void	draw_line(mlx_image_t *img, t_point p1, t_point p2);

void	draw_lines(mlx_image_t *img, t_map *map);

#endif
