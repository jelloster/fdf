/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:25:29 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/04 15:47:06 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * Hooks allow you to add your own functions to the main loop that get executed
 * every frame. Only one hook can be set at a time.
 */


int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	// Initialize and run a new window instance with resize ability
	mlx = mlx_init(RES_X, RES_Y, "fdf", true);
	if (!mlx)
		ft_error();

	// Create an image with n x n resolution
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Set the channels of each pixel in our image to 255 (wtf?)
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	// Draw the image at coordinates (0, 0)
	mlx_image_to_window(mlx, img, 0, 0);

	// Run the main loop and terminate on quit
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

