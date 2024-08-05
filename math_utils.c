#include "fdf.h"

/* 
	Interpolate

	Get a value in between s (start) and e (end) based on the value n
	that is between 0 and n_max.
*/

unsigned int	ip(int s, int e, int n, int n_max)
{
	double ratio;

	if (n_max == 0)
		return (s);
	ratio = (double)n / (double)n_max;
	return ((unsigned int)(s + ratio * (e - s) + 0.5));
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
