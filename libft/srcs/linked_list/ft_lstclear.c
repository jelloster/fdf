/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:55:35 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 12:47:56 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Desription : Deletes and frees the given node and every successor of that
 * node, using the function ’del’ and free(3). Finally, the pointer to the list
 * must be set to NULL. */

#include <stdlib.h>
#include "../../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*temp;

	if (lst == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		(*del)(node->content);
		temp = node->next;
		free(node);
		node = temp;
	}
	*lst = NULL;
}
