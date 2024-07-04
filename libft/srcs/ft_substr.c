/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:22:48 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/19 15:53:49 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description :  Allocates (with malloc(3)) and returns a substring from the
 * string ’s’. The substring begins at index ’start’ and is of maximum size
 * ’len’. */

#include "../inc/libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (len == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start <= len)
		sub = malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
