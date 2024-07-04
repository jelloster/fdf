/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:07:50 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/19 15:40:20 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : copies len bytes from string src to string dst. The two
 * strings may overlap; the copy is always done in a non-destructive manner.
 * Return value : original value of dst. */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (len == 0 || (!dst && !src))
		return (dst);
	if ((unsigned char *)dst > (unsigned char *)src)
	{
		i = len - 1;
		while (i > 0)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
