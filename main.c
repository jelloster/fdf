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

	if (ac == 2)
		init_map(av[1], &map);
	else
		ft_putstr_fd("Incorrect amount of arguments.\n", 2);

	// Initialize and run a new window instance with resize ability
	mlx = mlx_init(RES_X, RES_Y, "fdf", true);
	if (!mlx)
		ft_error();

	// Create an image with n x n resolution
	img = mlx_new_image(mlx, RES_X, RES_Y);

	// Set all pixels to white
	//ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	//
	for (uint32_t y = 0; y < img->height; y++) {
		for (uint32_t x = 0; x < img->width; x++) {
		    mlx_put_pixel(img, x, y, 0x00008B);
        }
    }

	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	draw_points(img, &map);
//	draw_line(img, map.grid[0][0], map.grid[map.h-1][map.w-1]);
	draw_lines(img, &map);

	// Run the main loop and terminate on quit
	mlx_loop(mlx);
	mlx_terminate(mlx);
	if (ac == 2)
		free_map_grid(&map, 0);
	return (EXIT_SUCCESS);
}
