/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:45:15 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 12:50:54 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : tests for any character for which isalpha(3) or isdigit(3) is
 * true.  The value of the argument must be representable as an unsigned char
 * or the value of EOF. */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
