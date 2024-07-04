/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:46:39 by motuomin          #+#    #+#             */
/*   Updated: 2024/04/22 16:13:20 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description : converts an upper-case letter to the corresponding lower-case 
 * letter.  The argument must be representable as an unsigned char or the value
 * of EOF. */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
