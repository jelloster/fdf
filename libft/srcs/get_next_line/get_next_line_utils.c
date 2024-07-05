/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:49:29 by motuomin          #+#    #+#             */
/*   Updated: 2024/07/04 16:07:41 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"
#include "../../inc/libft.h"

void	*ft_memdel(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

// modified strjoin where it frees
char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	x;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
	{
		ft_memdel(&s1);
		ft_memdel(&s2);
		return (NULL);
	}
	i = 0;
	x = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[x])
		res[i++] = s2[x++];
	res[i] = '\0';
	free(s1);
	free(s2);
	return (res);
}
