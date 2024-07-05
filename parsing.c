#include "fdf.h"

void	parse(int fd, t_map *map)
{
	char	*line;
	char	**split_line;
	int		x;
	int		y;

	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return;
		split_line = ft_split(line, ' ');
		if (!split_line)
			return ;
		

		/*
		x = 0;
		y = 0;
		while (split_line[i])
		{
		}
		*/



	}


}

int	add_string(t_file *file, char *str)
{
	char	**temp;
	int		i;

	i = 0;
	if (!file->lines)
		file->lines = malloc(sizeof(char *));
	temp = malloc((++file->size) * sizeof(char *));
	while (i < file->size - 2)
	{
		temp[i] = file->lines[i];
		i++;
	}
	temp[i++] = str;
	temp[i] = NULL;
	free_array_of_arrays
	return (1);
}

int	free_array_of_arrays(char **arr)
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


