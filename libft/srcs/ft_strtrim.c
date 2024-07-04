/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:42:01 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/19 11:59:35 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : Allocates (with malloc(3)) and returns a copy of ’s1’ with the
 * characters specified in ’set’ removed from the beginning and the end of the
 * string. */

#include <stdlib.h>
#include "../inc/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	trim = malloc(sizeof(char) * (end - start) + 2);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + start, end - start + 2);
	return (trim);
}
