/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:49:55 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 13:42:32 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : Adds the node ’new’ at the end of the list. */

#include "../../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (new == NULL || lst == NULL)
		return ;
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}
