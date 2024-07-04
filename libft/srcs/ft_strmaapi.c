/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmaapi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:51:31 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/18 15:01:57 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : Applies the function ’f’ to each character of the string ’s’,
 * and passing its index as first argument to create a new string (with
 * malloc(3)) resulting from successive applications of ’f’. */

#include <stdlib.h>
#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
