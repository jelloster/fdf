/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:25:57 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/04 14:25:41 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// --- INCLUDES ---
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_fdf {
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

// --- MACROS ---
# define RES_X 1080
# define RES_Y 1920

#endif
