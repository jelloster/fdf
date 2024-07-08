/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:25:57 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/08 16:54:23 by motuomin         ###   ########.fr       */
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

typedef struct s_fdf
{
	// Window
	void	*win;
	// Memory address where bytes will be mutated
	void	*addr;
	// Bits per pixel
	int		bpp;
	// Line length
	int		ll;
	// Endian
	int		endian;

}			t_fdf;

typedef struct s_file
{
	char	**lines;
	int		size;
}	t_file;

typedef struct s_point
{
	int	h;
	int	x;
	int	y;
}			t_point;

typedef struct	s_map
{
	int	w;
	int	h;
	t_point	**grid;
}				t_map;

// --- MACROS ---
# define RES_X 1080
# define RES_Y 1920

# define EXIT_FAILURE 1
# define EXIT_SUCESS 0

// --- FUNCTION PROTOTYPES ---

void	ft_error(void);

// memory_functions.c
int	allocate_map_grid(t_map *map);
int	free_map_grid(t_map *map, int ret);
int	free_array_of_arrays(char **arr);

// parsing.c
void	init_map(char *file, t_map *map);


#endif
