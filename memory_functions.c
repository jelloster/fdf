#include "fdf.h"

int	allocate_map_grid(t_map *map)
{
	int		i;

	map -> grid = malloc((map -> h) * (sizeof (t_map *)));
	if (!map -> grid)
		return (-1);
	i = 0;
	while (i < map -> h)
	{
		map -> grid[i] = malloc((map -> w) * (sizeof (t_map)));
		if (!map -> grid[i])
			return (free_map_grid(map, -1));
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
