/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:59:13 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 12:52:56 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : tests for an ASCII character, which is any character between 0
 * and octal 0177 inclusive. */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
