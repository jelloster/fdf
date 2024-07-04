/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:07:48 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/19 11:22:46 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : strlcpy() copies up to dstsize - 1 characters from the string
 * src to dst, NUL-terminating the result if dstsize is not 0. If the src and
 * dst strings overlap, the behavior is undefined.
 * Return value : the length of src. */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize != 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
