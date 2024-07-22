/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:51:17 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/22 13:34:37 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_map_dimensions(int fd, t_map *map);
static int	parse(int fd, t_map *map);
static int	get_min_and_max(t_map *map, int h, int w);

void	init_map(char *file, t_mlx *mlx, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_mlx_exit(mlx);
	if (access(file, R_OK) != 0 || get_map_dimensions(fd, map)
			|| map -> w == -1 ||  !allocate_map_grid(map))
	{
		close (fd);
		ft_putstr_fd("Map error.\n", 2);
		free_mlx_exit(mlx);
	}
	close (fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_mlx_exit(mlx);
	if (!parse(fd, map))
	{
		close(fd);
		free_mlx_exit(mlx);
	}
	gridmap(map, &get_min_and_max);
}

static int	get_map_dimensions(int fd, t_map *map)
{
	char	*line;
	char	**split_line;
	int		temp_w;

	line = get_next_line(fd);
	map -> w = -1;
	map -> h = 0;
	while (line)
	{
		temp_w = 0;
		map -> h++;
		split_line = ft_split(line, ' ');
		free (line);
		if (!split_line)
			return (0);
		while (split_line[temp_w])
			temp_w++;
		free_split(split_line);
		if (map -> w != -1 && temp_w != map -> w)
			return (0);
		map -> w = temp_w;
		line = get_next_line(fd);
	}
	return (1);
}

static int	parse(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**split_line;

	i = 0;
	while (i < map -> h)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		split_line = ft_split(line, ' ');
		if (!split_line)
		{
			free(line);
			return (0);
		}
		j = -1;
		while (++j < map -> w)
			map -> grid[i][j].value = ft_atoi(split_line[j]);
		free(line);
		free_split(split_line);
		i++;
	}
	return (1);
}

static int	get_min_and_max(t_map *map, int h, int w)
{
	if (map -> grid[h][w].value > map -> max)
		map -> max = map -> grid[h][w].value;
	if (map -> grid[h][w].value < map -> min)
		map ->min = map -> grid[h][w].value;
	return (1);
}
