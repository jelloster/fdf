/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:30:10 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 12:56:05 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Desription : Allocates (with malloc(3)) and returns a new node. The member
 * variable ’content’ is initialized with the value of the parameter ’content’.
 * The variable ’next’ is initialized to NULL. */

#include <stdlib.h>
#include "../../inc/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}
