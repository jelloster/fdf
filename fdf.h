/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:52:40 by motuomin          #+#    #+#             */
/*   Updated: 2024/09/18 13:59:52 by motuomin         ###   ########.fr       */
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
	long			x;
	long			y;
	long			value;
	unsigned int	c;
}					t_point;

typedef struct s_map
{
	int				h;
	int				w;
	int				max;
	int				min;
	long			range;
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

typedef struct s_br
{
	long				dx;
	long				ddx;
	long				dy;
	long				ddy;
	long				sx;
	long				sy;
	long				err;
	long				e2;
	long				t_l;
	unsigned int		color;
}						t_br;

typedef struct s_color
{
	int	r;
	int	b;
	int	g;
	int	a;
}					t_color;

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
}	t_dir;

// -- Macros --

# define RES_X		1200
# define RES_Y		800

# define MOVE_AMOUNT 100

//					0xRRGGBBAA
# define RED        0xFF0000FF
# define BLUE       0x0000FFFF
# define BLACK		0x00000FF

# define C1			BLUE
# define C2			RED
# define BG_C		BLACK

//				-- Function prototypes --

//				fdf.c
void			fdf(t_mlx *mlx, t_map *map);
void			finish_reading_file(int fd);

//				parsing.c
int				init_map(char *file, t_map *map);

//				memory_functions.c
void			free_mlx_exit(t_mlx *mlx, int ret);
int				free_split(char **arr);
int				allocate_map(t_map *map);
int				free_and_return(void *ptr, int ret);
int				free_map_grid(t_map *map, int ret);

//				math_utils.c
unsigned int	ip(long s, long e, long n, long n_max);
int				dis(t_point p1, t_point p2);

//				color_functions.c
unsigned int	gradient(t_point p1, t_point p2, int t_l);
void			get_point_color(t_point *point, t_map map);
void			background_color(t_mlx *mlx, unsigned int color);

//				draw_line.c
void			draw_line(mlx_image_t *img, t_point p1, t_point p2);

//				key_press.c
void			key_hook(mlx_key_data_t keydata, void *param);

//				move.c
void			move(t_mlx *mlx, t_dir dir);

//				main.c
void			draw_map(t_mlx *mlx, t_map *map);

//				zoom.c
void			zoom_in(t_mlx *mlx);
void			zoom_out(t_mlx *mlx);

#endif
