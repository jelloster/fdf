/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:25:57 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/19 17:05:05 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
// --- INCLUDES ---
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

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
	int	min_h;
	int	max_x;
	int	min_x;
	int	range;
	int	start;
	t_point	**grid;
}				t_map;

typedef struct s_screen
{
	int	half_tiles;
	int	half_tile_w;
	int	half_tile_h;

	int	t_h;
	int	mar_x;
	int	mar_y;
	t_map	*map;
	mlx_image_t	*img;
}	t_screen;

typedef enum e_dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
}	t_dir;

// --- MACROS ---
# define RES_X 2000
# define RES_Y 2500
# define MARGIN 0

#define ABS(x) ((x) < 0 ? -(x) : (x));

// Colors
#define RED       0xFF0000FF // black
#define GREEN     0x00FF00FF // green
#define BLUE      0x0000FFFF
#define YELLOW    0xFFFF00FF
#define CYAN      0x00FFFFFF // cyan
#define MAGENTA   0xFF00FFFF // blue
#define WHITE     0xFFFFFFFF // cyan
#define BLACK     0x000000FF // black

# define C1 BLUE
# define C2 WHITE

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

// math_utils.c
int	ip(int s, int e, int n, int n_max);
int	dis(t_point p1, t_point p2);

void	get_point_colors(t_map *map);

unsigned int	get_gradient_color(t_point p1, t_point p2, int t_l);

void	draw_points(mlx_image_t *img, t_map *map);

void	draw_line(mlx_image_t *img, t_point p1, t_point p2);

void	draw_lines(mlx_image_t *img, t_map *map);

void	key_hook(mlx_key_data_t keydata, void *param);

#endif
