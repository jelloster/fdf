#include "fdf.h"

void	zoom(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (h < map->h)
	{
	    w = -1;
	    while (++w < map->w)
			get_zoomed_coordinate(map);
	    h++;
	}
}

void	get_zoomed_coordinate(t_map *map)
{
	
}
