#include "fdf.h"

static int	get_dimensions(int fd, t_map *map);
static int	parse(int fd, t_map *map);

void	init_map(char *file, t_map *map)
{
	int	fd;


	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	map -> h = 0;
	map -> w = -1;
	if(!get_dimensions(fd, map))
	{
		close(fd);
		return ;
	}
	close(fd);
	fd = open(file, O_RDONLY);
	parse(fd, map);
	close(fd);
}

static int	get_dimensions(int fd, t_map *map)
{
	char	*line;
	char	**split_line;
	int		temp_w;

	line = get_next_line(fd);
	while (line)
	{
		temp_w = 0;
		map -> h++;
		split_line = ft_split(line, ' ');
		free (line);
		if (!split_line)
			return (-1);
		while (split_line[temp_w] != NULL)
			temp_w++;
		if (map -> w != -1 && temp_w != map -> w)
		{
			free(split_line);
			return (0);
		}
		else
			map -> w = temp_w;
		free(split_line);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}

static int	parse(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**split_line;;

	i = 0;
	while (i < map -> h)
	{
		line = get_next_line(fd);
		if (!line)
			return(free_map_grid(map, -1));
		split_line = ft_split(line, ' ');
		if (!split_line)
		{
			free(line);
			return(free_map_grid(map, -1));
		}
		j = 0;
		while (j < map -> w)
		{
			map -> grid[i][j].h = ft_atoi(split_line[j]);
			map -> grid[i][j].x = j;
			map -> grid[i][j].y = i;
			j++;
		}
		free(line);
		free_array_of_arrays(split_line);
		i++;
	}
	return (1);
}
