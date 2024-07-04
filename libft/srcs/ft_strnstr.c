/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:11:09 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/19 16:01:11 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : locates the first occurrence of the null-terminated string
 * needle in the string haystack, where not more than len characters are 
 * searched.  Characters that appear after a `\0' character are not searched.
 * Since the strnstr() function is a FreeBSD specific API, it should only be
 * used when portability is not a concern. */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i <= len - n_len)
	{
		if (i + n_len <= len && ft_memcmp(haystack + i, needle, n_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
