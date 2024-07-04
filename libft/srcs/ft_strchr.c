/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:43:53 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/19 10:47:53 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : locates the first occurrence of c (converted to a char) in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string; therefore if c is `\0', the functions locate the
 * terminating `\0'. */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
