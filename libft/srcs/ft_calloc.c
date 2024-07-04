/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:31:19 by motuomin          #+#    #+#             */
/*   Updated: 2024/06/12 15:14:16 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description :  contiguously allocates enough space for count objects that
 * are size bytes of memory each and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero. */

#include <stdlib.h>
#include <stdint.h>
#include "../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && SIZE_MAX / count <= size)
		return (NULL);
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}
