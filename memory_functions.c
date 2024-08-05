/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:29:54 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/22 13:26:43 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	free_map_grid(t_map *map, int ret);

void	free_mlx_exit(t_mlx *mlx, int ret)
{
	mlx_terminate(mlx -> mlx);
	/*
	if (mlx -> img1)
	{
		mlx_destroy_image(mlx->mlx, mlx->img1);
		mlx -> img1 = NULL;
	}
	*/
	free_map_grid(mlx -> map, 0);
	exit (ret);
}

int	allocate_map_grid(t_map *map)
{
	int		i;

	map -> grid = malloc((map -> h) * (sizeof (t_map *)));
	if (!map -> grid)
		return (0);
	i = 0;
	while (i < map -> h)
	{
		map -> grid[i] = malloc((map -> w) * (sizeof (t_map)));
		if (!map -> grid[i])
			return (free_map_grid(map, 0));
		i++;
	}
	return (1);
}

static int	free_map_grid(t_map *map, int ret)
{
	int	i;

	i = 0;
	if (map -> grid)
	{
		while (i < map -> h)
		{
			if (map -> grid[i])
				free(map -> grid[i]);
			map -> grid[i] = NULL;
			i++;
		}
		free(map -> grid);
	}
	free (map);
	map = NULL;
	return (ret);
}

int	free_split(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			if (arr[i])
			{
				free(arr[i]);
				arr[i] = NULL;
			}
			i++;
		}
		free(arr);
		arr = NULL;
	}
	return (-1);
}
