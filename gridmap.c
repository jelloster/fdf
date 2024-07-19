#include "fdf.h"

void	gridmap(t_map *map, void (*f)(t_map *, int, int))
{
	int	h;
	int	w;

	h = 0;
	while (h < map->h)
	{
	    w = 0;
	    while (++w < map->w)
		{
			(*f)(map, h, w);
			w++;
		}
	    h++;
	}
}
