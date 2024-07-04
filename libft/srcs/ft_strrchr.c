/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:48:49 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/19 10:52:12 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : locates the LAST occurrence of c (converted to a char)
 * in the string pointed to by s. The terminating null character is considered
 * to be part of the string; therefore if c is `\0', the functions locate the
 * terminating `\0'.*/

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s[i--] == (char)c)
		return ((char *)(s + i + 1));
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
