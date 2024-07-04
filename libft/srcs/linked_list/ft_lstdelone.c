/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:53:17 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 12:44:13 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Desription : Takes as a parameter a node and frees the memory of the node’s
 * content using the function ’del’ give as a parameter and free the node.
 * The memory of ’next’ must not be freed. */

#include "../../inc/libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
		(*del)(lst -> content);
	free (lst);
}
