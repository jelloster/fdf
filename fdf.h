/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:52:40 by motuomin          #+#    #+#             */
/*   Updated: 2024/08/19 12:34:17 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// -- Includes --

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/inc/libft.h"

// -- Typedefs --

typedef struct s_point
{
	int				res_x;
	int				res_y;
	int				value;
	unsigned int	c;
}					t_point;

typedef struct s_map
{
	int				h;
	int				w;
	int				max;
	int				min;
	int				range;
	t_point			**grid;
}					t_map;

typedef struct s_screen
{
	int				half_tiles;
	int				half_tile_w;
	int				half_tile_h;
	int				mar_x;
	int				mar_y;
	int				start_x;
}					t_screen;

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*img1;
	t_map			*map;
	t_screen		s;
}					t_mlx;

typedef struct s_bresenhamn
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
	int				t_l;
	unsigned int	color;
}	t_bresenhamn;

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_dir;

// -- Macros --

# define RES_X		2500
# define RES_Y		1500

# define MOVE_AMOUNT 100

# define BLUE		0x0000FFFF
# define WHITE		0xFFFFFFFF

# define C1			BLUE
# define C2			WHITE
# define BG_C		0x00008B

//				-- Function prototypes --

//				fdf.c
void			fdf(t_mlx *mlx, t_map *map);

//				parsing.c
int				init_map(char *file, t_map *map);

//				memory_functions.c
void			free_mlx_exit(t_mlx *mlx, int ret);
int				free_split(char **arr);
int				allocate_map_grid(t_map *map);

//				math_utils.c
unsigned int	ip(int s, int e, int n, int n_max);
int				dis(t_point p1, t_point p2);

//				color_functions.c
unsigned int	gradient(t_point p1, t_point p2, int t_l);
void			get_point_colors(t_map *map);

//				draw_line.c
void			draw_line(mlx_image_t *img, t_point p1, t_point p2);

//				key_press.c
void			key_hook(mlx_key_data_t keydata, void *param);

//				move.c
void			move(t_mlx *mlx, t_dir dir);

//	main.c
void			draw_map(t_mlx *mlx, t_map *map);

//				zoom.c
void			zoom_in(t_mlx *mlx);
void			zoom_out(t_mlx *mlx);

//				background.c
void			background_color(t_mlx *mlx, unsigned int color);

#endif
