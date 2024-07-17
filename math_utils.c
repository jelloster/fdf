#include "fdf.h"

/* 
	Interpolate

	Get a value in between s (start) and e (end) based on the value n
	that is between 0 and n_max.
*/

int	ip(int s, int e, int n, int n_max)
{
	if (n_max == 0)
		return (0);
    return (s + ((e - s) * n) / n_max);
}

/*
	Length

	Get the distance between 2 points
*/

int	dis(t_point p1, t_point p2)
{
	return (sqrt(pow((p2.res_x - p1.res_x), 2)
	  + pow((p2.res_y - p1.res_y), 2)));
}
