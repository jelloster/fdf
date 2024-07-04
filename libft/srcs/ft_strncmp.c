/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:04:00 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 16:15:52 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Desription : compares not more than n characters.  Because strncmp() is 
 * designed for comparing strings rather than binary data, characters that
 * appear after a `\0' character are not compared. */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return ((unsigned char)(s1[i - 1]) - (unsigned char)(s2[i - 1]));
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
