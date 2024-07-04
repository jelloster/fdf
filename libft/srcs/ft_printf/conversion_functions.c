/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:29:08 by motuomin          #+#    #+#             */
/*   Updated: 2024/05/14 09:39:16 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/* Writes a given int to print_info buffer */
int	putnbr_str(int n, t_print_info *p_i)
{
	char	c;

	if (n == -2147483648)
		return (write_to_buf_str("-2147483648", p_i));
	if (n < 0)
	{
		if (write_to_buf('-', p_i) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if (putnbr_str(n / 10, p_i) == -1)
			return (-1);
		n = n % 10;
	}
	if (n < 10)
	{
		c = n + '0';
		return (write_to_buf(c, p_i));
	}
	return (-1);
}

/* Writes a given unsigned in to print_info_buffer */
int	put_unsigned_nbr_str(unsigned int n, t_print_info *p_i)
{
	char	c;

	if (n >= 10)
	{
		if (put_unsigned_nbr_str(n / 10, p_i) == -1)
			return (-1);
		n = n % 10;
	}
	if (n < 10)
	{
		c = n + '0';
		return (write_to_buf(c, p_i));
	}
	return (-1);
}

/* Writes a given unsigned long long to print_info buffer in hexadecimal
 * format */
int	write_hex(unsigned long long nbr, char *base, t_print_info *p_i)
{
	int		i;
	char	result[100];

	i = 0;
	if (nbr == 0)
		return (write_to_buf(base[0], p_i));
	while (nbr)
	{
		result[i] = base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
	{
		if (write_to_buf(result[i], p_i) == -1)
			return (-1);
	}
	return (1);
}
