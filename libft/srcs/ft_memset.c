/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:27:38 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/18 10:13:03 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description:  writes len bytes of value c (converted to an unsigned char)
 * to the string b.
 * Return value : first argument */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
