/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:13:50 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 15:44:55 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : Iterates the list ’lst’ and applies the function ’f’ on the
 * content of each node. Creates a new list resulting of the successive
 * applications of the function ’f’. The ’del’ function is used to delete the 
 * content of a node if needed.
 *
 * Return value : The new list. NULL if the allocation fails.*/

#include <stdlib.h>
#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*next;
	void	*mapped;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	while (lst != NULL)
	{
		mapped = f(lst->content);
		next = ft_lstnew(mapped);
		if (!next)
		{
			del(mapped);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, next);
		lst = lst->next;
	}
	return (res);
}
