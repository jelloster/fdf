/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:29:54 by motuomin          #+#    #+#             */
/*   Updated: 2024/09/11 14:03:59 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mlx_exit(t_mlx *mlx, int ret)
{
	mlx_terminate(mlx -> mlx);
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

int	free_map_grid(t_map *map, int ret)
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

int	free_and_return(void *ptr, int ret)
{
	free (ptr);
	return (ret);
}
