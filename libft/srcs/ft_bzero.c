/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:40:14 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/18 10:18:14 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : writes n zeroed bytes to the string s.  If n is zero,
 * bzero() does nothing. */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
