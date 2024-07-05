/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:25:57 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/05 13:27:13 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// --- INCLUDES ---
# include "MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
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

#endif
