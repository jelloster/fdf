/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:30 by motuomin          #+#    #+#             */
/*   Updated: 2024/09/16 17:05:06 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ip(long s, long e, long n, long n_max)
{
	double	ratio;

	if (n_max == 0)
		return (s);
	ratio = (double)n / (double)n_max;
	return ((unsigned int)((unsigned long)(s + ratio * (e - s) + 0.5)));
}

int	dis(t_point p1, t_point p2)
{
	int	res;

	res = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	return (res);
}
