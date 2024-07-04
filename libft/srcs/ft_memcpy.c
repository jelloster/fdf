/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:53:57 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 16:06:35 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : The memcpy() function copies n bytes from memory area src to
 * memory area dst. If dst and src overlap, behavior is undefined. Applications
 * in which dst and src might overlap should use memmove(3)	instead. Return
 * value : the original value of dst. */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
