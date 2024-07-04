/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:44:03 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 16:12:29 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : The toupper() function converts a lower-case letter to the
 * corresponding upper-case letter. The argument must be representable as an
 * unsigned char or the value of EOF.*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
