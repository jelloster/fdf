/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/09/09 12:44:54 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ip(int s, int e, int n, int n_max)
{
	double	ratio;

	if (n_max == 0)
		return (s);
	ratio = (double)n / (double)n_max;
	return ((unsigned int)(s + ratio * (e - s) + 0.5));
}

int	dis(t_point p1, t_point p2)
{
	int	res;

	res = sqrt(pow(p2.res_x - p1.res_x, 2) + pow(p2.res_y - p1.res_y, 2));
	return (res);
}
