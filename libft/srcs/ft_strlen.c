/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:51:43 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 16:16:45 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : computes the length of the string s.  The strnlen() function
 * attempts to compute the length of s, but never scans beyond the first maxlen
 * bytes of s. */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
