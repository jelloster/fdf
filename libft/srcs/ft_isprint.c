/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:04:57 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 12:54:41 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : function tests for any printing character, including space
 * (` ').  The value of the argument must be representable as an unsigned char
 * or the value of EOF. */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
