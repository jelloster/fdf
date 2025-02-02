/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:51:17 by motuomin          #+#    #+#             */
/*   Updated: 2024/09/12 17:02:11 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_map_dimensions(int fd, t_map *map);
static int	parse(int fd, t_map *map);
static void	get_min_and_max(t_map *map);
static int	name(char *file);

int	init_map(char *file, t_map *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1 || !get_map_dimensions(fd, map) || map->w == -1
		|| !name(file) || map->w > 5000 || map->h > 5000 || !allocate_map(map))
	{
		finish_reading_file(fd);
		if (fd != -1)
			close (fd);
		return (0);
	}
	close (fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free_map_grid(map, 0));
	if (!parse(fd, map))
	{
		close(fd);
		return (free_map_grid(map, 0));
	}
	close(fd);
	get_min_and_max(map);
	return (1);
}

static int	name(char *file)
{
	if (ft_strlen(file) < 4)
		return (0);
	if (ft_strlen(file) == 4)
		if (ft_strncmp(file, ".fdf", ft_strlen(file)) != 0)
			return (0);
	file += ft_strlen(file) - 4;
	if (ft_strncmp(file, ".fdf", ft_strlen(file)) != 0)
		return (0);
	return (1);
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
	line = get_next_line(fd);
	while (line)
	{
		if (!line)
			return (0);
		split_line = ft_split(line, ' ');
		if (!split_line)
			return (free_and_return(line, 0));
		j = -1;
		while (++j < map -> w)
			map -> grid[i][j].value = ft_atoi(split_line[j]);
		free(line);
		free_split(split_line);
		line = get_next_line(fd);
		i++;
	}
	return (1);
}

static void	get_min_and_max(t_map *map)
{
	int	h;
	int	w;

	map -> max = map -> grid[0][0].value;
	map -> min = map -> grid[0][0].value;
	h = 0;
	while (h < map->h)
	{
		w = 0;
		while (w < map->w)
		{
			if (map -> grid[h][w].value > map -> max)
				map -> max = map -> grid[h][w].value;
			if (map -> grid[h][w].value < map -> min)
				map ->min = map -> grid[h][w].value;
			w++;
		}
		h++;
	}
	map -> range = (long)map->max - (long)map->min;
}
