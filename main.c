/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:25:29 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/04 14:25:50 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* you need 2 images so you can write to the one that is not currently
 * presented (to prevent screen tearing);
 */
void	pxl_put(t_fdf img, int x, int y, int color);

int	main(void)
{
	void	*mlx;
//	t_fdf	img;
//	void	*mlx_win;

	// Init MLX
	mlx = mlx_init(RES_X, RES_Y, "fdf", true);

	/*
	// Init some window
	img.win = mlx_new_window(mlx, RES_X, RES_Y, "fdf");

	// Get address of ?
	img.addr = mlx_get_data_addr(img.win, &img.bpp, &img.ll, &img.endian);

	pxl_put(img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_wi, img.win, 0, 0);
	*/
	// 
	mlx_loop(mlx);

	return (0);
}

void	pxl_put(t_fdf img, int x, int y, int color)
{
	char	*dst;
// line_length differs from the actual window width. We therefore should ALWAYS
// calculate the memory offset using the line length set by mlx_get_data_addr
	dst = img.addr + (y + img.ll + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
