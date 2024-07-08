/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:25:29 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/08 16:55:42 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * Hooks allow you to add your own functions to the main loop that get executed
 * every frame. Only one hook can be set at a time.
 */


int	main(int ac, char *av[])
{
	mlx_t		*mlx;
	t_map		map;
	mlx_image_t	*img;

	int fd = open(av[1], O_RDONLY);
	get_next_line(fd);
	close(fd);

	// Initialize and run a new window instance with resize ability
	if (ac == 2)
		init_map(av[1], &map);
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

