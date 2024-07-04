/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:57:56 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 12:52:06 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : tests for any character for which isupper(3) or islower(3) is
 * true.  The value of the argument must be representable as an unsigned char
 * or the value of EOF. */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
