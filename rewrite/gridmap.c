/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:58:49 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/22 13:29:31 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gridmap(t_map *map, int (*f)(t_map *, int, int))
{
	int	h;
	int	w;

	h = 0;
	while (h < map->h)
	{
		w = 0;
		while (++w < map->w)
		{
			if (!(*f)(map, h, w))
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}
